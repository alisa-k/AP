#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SIZE 4096

void die(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char **argv)
{
    
    char *host;                     /* host argv[1] */
    char *port;                     /* port argv[2] */
    char *filePath;                 /* file path argv[3] */ 

    int sock;                       /* socket file descriptor */
    struct sockaddr_in serverAddr;  /* server address */
    unsigned short serverPort;      /* server port */
    char *serverIP;                 /* server IP */
    struct hostent *he;             /* used to convert host name into IP address*/
    
    FILE *fpSock;                   /* socket file pointer */
    FILE *fpHTML;                   /* make.html file pointer */
    char *fileName;                 /* name of file to be written to*/
    
    char buffer[SIZE];
    size_t n;

    // check if correct number of command line arguments entered 
    if (argc != 4)
    {
        fprintf(stderr, "usage: %s <host> <port_number> <file_path>\n", argv[0]);
        exit(1);
    }

    // get server ip from server name (argv[1])
    host = argv[1];
    if ((he = gethostbyname(host)) == NULL) {
        die("gethostbyname() failed");
    }
    serverIP = inet_ntoa(*(struct in_addr *)he->h_addr);
    
    // get serverPort as unsigned short and filePath
    port = argv[2];
    serverPort = atoi(port);
    filePath = argv[3];
    

     /* Create a reliable, stream socket using TCP */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        die("socket() failed");

    /* Construct the server address structure */
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(serverPort);

    /* Establish the connection to the server */
    if (connect(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
        die("connect() failed");

    /* Send request to the server */
    if (sprintf(buffer, "GET %s HTTP/1.0\r\nHost: %s:%s\r\n\r\n", filePath, host, port) == -1)
    {
        fprintf(stderr, "sprintf() error\n");
        exit(1);
    }
    if (send(sock, buffer, strlen(buffer), 0) != strlen(buffer))
        die("send() failed");

    /* Recieve response from server */
    if ((fpSock = fdopen(sock, "r")) == 0)
        die("fdopen() failed");

    // check if request was successful
    if (fgets(buffer, sizeof(buffer), fpSock) == 0)
    {   
        // check for reading or connection errors
        if (ferror(fpSock))
        {
            fclose(fpSock);
            die("reading error");
        }
        else 
        {
            fclose(fpSock);
            die("connection closed prematurely");
        }
    }
    
    if (strstr(buffer, "200") == NULL)
    {   
        // request failed; print first line and exit
        fprintf(stderr, "%s", buffer);
        fclose(fpSock);
        exit(1);
    }    

    // read until we find blank line
    while (1)
    {
        if (fgets(buffer, sizeof(buffer), fpSock) == NULL)
        {
            if (ferror(fpSock))
            {
                fclose(fpSock);
                die("reading error");
            }
            fclose(fpSock);
            die("connection error");
        }
        if (!strcmp(buffer, "\r\n"))
            break;
    }
    
    // open file to write to
    if ((fileName = strrchr(filePath, '/')) == NULL)
    {
        fclose(fpSock);
        fprintf(stderr, "file path error");
        exit(1);
    }
    fileName++;
    if ((fpHTML = fopen(fileName, "wb")) == NULL)
    {
        fclose(fpSock);
        die("fopen() failed");
    }

    // write everything after blank line to fpHTML
    while((n = fread(buffer, 1,  sizeof(buffer), fpSock)) > 0)
    {
        if (fwrite(buffer, 1, n, fpHTML) != n)
        {
            fclose(fpHTML);
            fclose(fpSock);
            die("fwrite() failed");
        }
    }
    if(ferror(fpSock))
    {
        fclose(fpHTML);
        fclose(fpSock);
        die("fread() failed");
    }

    // close file and socket
    fclose(fpHTML);
    fclose(fpSock);

    return 0;
}

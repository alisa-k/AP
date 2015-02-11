
/*
 * mdb-lookup-server.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h> 
#include <arpa/inet.h>  
#include <unistd.h>     
#include <signal.h>

#include "mylist.h"
#include "mdb.h"

#define KeyMax 5
#define MAXPENDING 5
#define SIZE 1000

int loadmdb(FILE *fp, struct List *dest) 
{
    /* Read all records into memory */

    struct MdbRec r;
    struct Node *node = NULL;
    int count = 0;

    while (fread(&r, sizeof(r), 1, fp) == 1) {

        // allocate memory for a new record and copy into it the one
        // that was just read from the database.
        struct MdbRec *rec = (struct MdbRec *)malloc(sizeof(r));
        if (!rec)
            return -1; 
        memcpy(rec, &r, sizeof(r));

        // add the record to the linked list.
        node = addAfter(dest, node, rec);
        if (node == NULL) 
            return -1; 

        count++;
    }   

    /* See if fread() produced error */
    if (ferror(fp)) 
        return -1; 

    return count;
}

void freemdb(struct List *list) 
{
    /* Free all the records */
    traverseList(list, &free);
    removeAllNodes(list);
}


static void die(const char *message)
{
    perror(message);
    exit(1); 
}

void HandleTCPClient(int clntSocket, char *db_name)
{    
    char buffer[SIZE];       /* Buffer for string */
    FILE *fp;
    struct List list;
    FILE *input;     
    int loaded;
    char line[SIZE];
    char key[KeyMax + 1];

    /* Open database file (db_name) */
    fp = fopen(db_name, "rb");
    if (fp == NULL) 
        die(db_name);

    /* Read all records into memory */
    initList(&list);

    loaded = loadmdb(fp, &list);
    if (loaded < 0)
    {
        fclose(fp);
        die("loadmdb() failed");
    }
    fclose(fp);

    /* Lookup loop */
    if ((input = fdopen(clntSocket, "r")) == NULL)
        die("fdopen() failed");

    while (fgets(line, sizeof(line), input) != NULL) {

        size_t last;
        struct Node *node;
        int recNo;
        int len;

        // must null-terminate the string manually after strncpy().
        strncpy(key, line, sizeof(key) - 1); 
        key[sizeof(key) - 1] = '\0';

        // if newline is there, remove it.
        last = strlen(key) - 1;
        if (key[last] == '\n')
            key[last] = '\0';

        // traverse the list, printing out the matching records
        node = list.head;
        recNo = 1;
        while (node) {
            struct MdbRec *rec = (struct MdbRec *)node->data;
            if (strstr(rec->name, key) || strstr(rec->msg, key)) {
                len = sprintf(buffer, "%4d: {%s} said {%s}\n", recNo, rec->name, rec->msg);
                if (send(clntSocket, buffer, len, 0) != len){
                    perror("send() failed");
                    break;
                }
            }
            node = node->next;
            recNo++;
        }
        // send empty line
        len = sprintf(buffer, "\n");
        if (send(clntSocket, buffer, len, 0) != len)
            perror("send() failed");
    }

    freemdb(&list);       /* Free mdb */
    fclose(input);        /* Close client socket */
}

int main(int argc, char **argv)
{
    int servSock;                       /* Socket descriptor for server */
    int clntSock;                       /* Socket descriptor for client */
    struct sockaddr_in servAddr;        /* Local address */ 
    struct sockaddr_in clntAddr;        /* Client address */
    unsigned short servPort;            /* Server port */
    unsigned int clntLen;               /* Length of client address data structure */


    // ignore SIGPIPE so that we don’t terminate when we call
    // send() on a disconnected socket.
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) 
        die("signal() failed");

    /* User must specify exactly 2 command line arguments */
    if (argc != 3) {
        fprintf(stderr, "%s\n", "usage: mdb-lookup-server <database_file> <port_number>");
        exit(1);
    }

    /* Local Port */
    if ((servPort = atoi(argv[2])) == 0)
    {
        fprintf(stderr, "not a valid server port number");
        exit(1);
    }
    
    /* Create socket for incoming connections */
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        die("socket() failed");
    
    /* Construct local address structure */
    memset(&servAddr, 0, sizeof(servAddr));         /* Zero out structure */
    servAddr.sin_family = AF_INET;                  /* Internet address family */
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);   /* Any incoming interface */
    servAddr.sin_port = htons(servPort);            /* Local port */

    /* Bind to the local address */
    if (bind(servSock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)
        die("bind() failed");

    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock, MAXPENDING) < 0)
        die("listen() failed");

    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        clntLen = sizeof(clntAddr);

        /* Wait for a client to connect*/
        if ((clntSock = accept(servSock, (struct sockaddr *) &clntAddr,
                               &clntLen)) < 0)
            die("accept() failed");

        /* clntSock is connected to a client! */

        printf("Handling client %s\n", inet_ntoa(clntAddr.sin_addr));

        HandleTCPClient(clntSock, argv[1]);
    }

    return 0;
}

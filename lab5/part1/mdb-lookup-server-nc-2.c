
/*
 * mdb-lookup-server-nc-2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

struct timespec t;

static void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char **argv)
{
    char buffer[1000];
    char *p = buffer;
    pid_t pid;

    // infinite loop, breaks on Ctrl-C
    while(1)
    {
        // check if any child has been terminated and displays the message
        while ((pid = waitpid((pid_t) - 1, NULL, WNOHANG)) > 0)
        {
            fprintf(stderr, "[pid=%d] mdb-lookup-server-terminated \n", (int)pid);
        }
        
        // prompt user to enter the port number
        printf("port number: ");
        
        // fill the buffer with null characters
        memset(buffer, '\0', sizeof(buffer));

        // get the user's input for the port number
        if (fgets(buffer, sizeof(buffer), stdin))
        {
            if (buffer[0] == '\n')
            {
                // if user presses enter, display new prompt
                continue;
            }
            else 
            {
                // get the port number (we assume it's valid)
                while(*p != '\0')
                {
                    if (*p == '\n')
                    {
                        *p = '\0';
                        break;
                    }
                    p++;
                }
            }
        }
        else
        {   
            // if error occurs, continue
            continue;
        }

        // create a child process
        pid = fork();

        if (pid < 0)
        {
            die("fork failed");
        }
        else if (pid == 0)
        {
            // child process
            fprintf(stderr, "[pid=%d] mdb-lookup-server started on port %s\n", (int)getpid(), buffer);
            execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", buffer, (char *)0);
            die("execl failed");
        }
        else
        {
            // parent process
            
            // sleep for 1/3 seconds (for print order purposes)
            t.tv_sec = 0;
            t.tv_nsec = 333333333;
            nanosleep(&t, NULL);
        }
    }
    return 0;
}


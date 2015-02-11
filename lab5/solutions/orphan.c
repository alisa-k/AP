
/*
 * orphan.c
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

static void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char **argv)
{
    pid_t pid = fork();
    if (pid < 0) {
	die("fork failed");
    } else if (pid == 0) {
	// child process
    printf("\nChild has started: %d\n ",getpid());
    printf("\nParent of this child : %d\n",getppid());
    printf("\nchild prints 1 item :\n ");
    printf("\nchild prints 2 item :\n");
    sleep(5);
    } else {
	// parent process
    printf("\nParent has started: %d\n",getpid());
    printf("\nParent of the parent proc : %d\n",getppid());
    }
    printf("\nAfter fork()\n");
    return 0;
}


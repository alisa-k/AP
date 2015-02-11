
/*
 * zombie.c
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
    printf("child pid: %d\n", (int)getpid());
    } else {
	// parent process
    printf("parent pid: %d\n", (int)getpid());
	sleep(30);
    }
    return 0;
}


/*
 * twecho
 * CS 3157 Lab #2
 * Due: 9/29/14
 * Alisa Krivokapic (ak3533)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Creates a copy of the argv array with all-caps version of each argument.
 */
static char **duplicateArgs(int argc, char **argv)
{
    int i;
    int j;
    char **copy;
    
    // allocate memory for the array of char pointers
    copy = (char **) malloc((argc + 1) * sizeof(char *));
    
    // check return value of malloc()
    if (copy == NULL)
    {
        perror("malloc returned NULL");
        exit(1);
    }

    for (i = 0; i < argc; i++)
    {
        // allocate memory for each string
        copy[i] = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));
        
        // check return value of malloc()
        if (copy[i] == NULL)
        {
            perror("malloc returned NULL");
            exit(1);
        }

        for (j = 0; j < strlen(argv[i]); j++)
        {
           // capitalize each character of current string
           copy[i][j] = toupper(argv[i][j]);
        }
        copy[i][j] = '\0'; // last element of a char array is a null character
    }
    copy[argc] = NULL; // required by standard to be a null pointer

    return copy;
}

/*
 * Frees memory we allocated in duplicateArgs function
 */
static void freeDuplicatedArgs(char **copy)
{
    int i = 0;
    
    // free memory allocated for each string
    while (copy[i])
    {
        free(copy[i++]);
    }
    
    // free array of pointers
    free(copy);
}

/*
 * DO NOT MODIFY main().
 */
int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;

    char **copy = duplicateArgs(argc, argv);
    char **p = copy;

    argv++;
    p++;
    while (*argv) {
        printf("%s %s\n", *argv++, *p++);
    }

    freeDuplicatedArgs(copy);

    return 0;
}

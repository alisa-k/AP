#include <stdio.h>
#include <string.h>
#include "mylist.h"


/*
 * print command line arguments 
 */
void printData(void *str)
{
    printf("%s\n", (char *)str);
}

int main(int argc, char **argv)
{
    int i;
    struct List l;
    struct Node *pn;
    
    // initialize the list
    initList(&l);

    // populate the list 
    for (i = 1; i < argc; i++)
    {
        addFront(&l, argv[i]);
    }

    // print the data from the list
    traverseList(&l, printData);
    
    // search for the word "dude"
    pn = findNode(&l, "dude", (int (*)(const void *, const void *))strcmp);
    
    if (pn)
    {
        printf("\ndude found\n");
    }
    else
        printf("\ndude not found\n");

    // remove all nodes & free the memory
    removeAllNodes(&l);
    
    return 0;
}

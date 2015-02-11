#include <stdio.h>
#include <string.h>
#include "mylist.h"

void printData(void *str)
{
    printf("%s\n", (char *)str);
}
/*
int compareStrings(const void *str1, const void *str2)
{
    return strcmp((const char *)str1, (const char*)str2);
}*/

int main(int argc, char **argv)
{
    int i;
    struct List l;
    struct Node *pn;
    initList(&l);

    for (i = 1; i < argc; i++)
    {
        addFront(&l, argv[i]);
    }

    traverseList(&l, printData);
    
    pn = findNode(&l, "dude", (int (*)(const void *, const void *))strcmp);
    
    if (pn)
    {
        printf("\ndude found\n");
    }
    else
        printf("\ndude not found\n");

    removeAllNodes(&l);
    
    return 0;
}

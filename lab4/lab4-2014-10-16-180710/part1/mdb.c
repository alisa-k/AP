#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mylist.h" 
#include "mdb.h"

#define SIZE 1000

int lookup(struct List *pl)
{
    char *s;
    char *p;
    char buffer[SIZE];
    char search_str[6];
    struct Node *pn;
    int line_nbr = 1;

    printf("lookup : ");
    s = fgets(buffer, sizeof(buffer), stdin);
    
    // fgets does not return NULL if some characters are already entered
    // before EOF or an error occurrence; Ctrl-D has to be pressed twice to stop
        
    if (feof(stdin))
    {
        // ctrl-D pressed, stop the search
        return 2;
    }

    if (ferror(stdin))
    {
        // input error, continue with next search
        fflush(stdin);
        return 1;
    }

    if((p = strchr(buffer, '\n')) == NULL)
    {
        // input too long, continue with next search
        fflush(stdin);
        return 1;
    }
    else
    {
        // replace '\n' by '\0' in buffer
        // this handles the case when < 5 characters entered
        *p = '\0';
    }
    
    // copy first 5 characters to the search buffer
    strncpy(search_str, s, 5);
    search_str[5] = '\0';

    // search loaded records
    pn = pl->head;
    while (pn != NULL)
    {
        if (strstr(((struct MdbRec *)pn->data)->name, search_str) != NULL || strstr(((struct MdbRec *)pn->data)->msg, search_str) != NULL)
        {
            printf(" %d: {%s} said {%s}\n", line_nbr, ((struct MdbRec *)pn->data)->name, ((struct MdbRec *)pn->data)->msg);
        }
        line_nbr++;
        pn = pn->next;
    }
    return 0;
}

/* return 1 if error, 0 if success */
int loadmdb(FILE *fp, struct List *dest)
{
    struct Node *pn = NULL;
    struct MdbRec *precord;
    size_t n;

    while (!feof(fp))
    {   
        precord = (struct MdbRec *) malloc(sizeof(struct MdbRec));

        if (precord == NULL)
        {
            printf("Malloc returned null.\n");
            fclose(fp);
            return 1;
        }
        
        // read current record
        n = fread(precord, sizeof(struct MdbRec), 1, fp);
        
        if (n != 1)
        {
            // have to deallocate this
            free(precord);
            
            // return when end of file reached
            if (feof(fp))
                return 0;
            
            // return if reading error
            if (ferror(fp))
            {
                printf("Error reading file.\n");
                return 1;
            }
        }

        // add node for this record
        pn = addAfter(dest, pn, precord);

        if (pn == NULL)
        {
            printf("Error adding to list.\n");
            free(precord);
            return 1;
        }
    }
    return 0;
}

int main (int argc, char **argv)
{
    struct List l;
    FILE *fp;
    struct Node *pn;
    int result;

    // user needs to have exactly 1 command line argument
    if (argc != 2)
    {
        printf("Please specify the database file.\n");
        return 0; 
    }

    // initialize the list
    initList(&l);

    // opens binary file to read it
    fp = fopen(argv[1], "rb");

    if (fp == NULL) 
    {
        printf("Error opening file.\n");
        return 0;
    }
    
    // load mdb and search
    if (!loadmdb(fp, &l))
    {
        // stop searching if Ctrl-D pressed
        while ((result = lookup(&l)) != 2)
        {
            printf("\n");
        }
    }
    
    // free allocated memory
    pn = l.head;
    while (pn != NULL)
    {
        free(pn->data);
        pn = pn->next;
    }
    removeAllNodes(&l);
    
    // close database file
    if (fclose(fp) != 0)
        printf("Error closing file.\n");

    return 0;
}

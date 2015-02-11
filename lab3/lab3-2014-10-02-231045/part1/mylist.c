#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mylist.h"

struct Node *addFront(struct List *list, void *data)
{
    struct Node *pn;

    if (list == NULL)
    {
        printf("Error: Pointer to the list is a NULL pointer!\n");
        return NULL;
    }

    // create node
    pn = (struct Node *)malloc(sizeof(struct Node)); 

    if (pn == NULL)
    {
        printf("Failure: malloc returned NULL");
        return pn;
    }

    // the new created node will become the head of the list
    pn->data = data;
    pn->next = list->head;
    list->head = pn;

    return pn;
}

void traverseList(struct List *list, void (*f)(void *))
{
    struct Node *pn;

    if (list == NULL)
    {
        printf("Error: Pointer to the list is a NULL pointer!\n");
        return;
    }

    if( isEmptyList(list) )
    {
        return;
    }

    pn = list->head;

    // go node by node
    while(pn != NULL)
    {
        f(pn->data);
        pn = pn->next;
    }
}

void flipSignDouble(void *data)
{
    if(data == NULL)
    {
        perror("NULL data pointer!\n");
        return;
    }

    *(double *)data *= -1;
}

int compareDouble(const void *data1, const void *data2)
{
    if (*(double *) data1 == *(double *) data2)
        return 0;

    return 1;
}

struct Node *findNode(struct List *list, const void *dataSought, int (*compar)(const void *, const void *))
{
    struct Node *pn;

    if (list == NULL)
    {
        printf("Error: Pointer to the list is a NULL pointer!\n");
        return NULL;
    }

    if( isEmptyList(list) )
    {
        return NULL;
    }

    // start with the head
    pn = list->head;

    while(pn != NULL)
    {
        if (compar(pn->data, dataSought) == 0)
        {
            // node found
            return pn;
        }

        // continue to search
        pn = pn->next;
    }

    // not found
    return NULL;
}

void *popFront(struct List *list)
{
    struct Node *pn;
    void *tdata;
    
    if (list == NULL)
    {
        printf("Error: Pointer to the list is a NULL pointer!\n");
        return NULL;
    }

    if( isEmptyList(list) )
    {
        return NULL;
    }

    // save the data
    pn = list->head;
    tdata = pn->data;

    // set the new head of the list
    list->head = pn->next;

    // deallocate the original head
    free(pn);

    return tdata;
}

void removeAllNodes(struct List *list)
{
    struct Node *pn;

    if (list == NULL)
    {
        printf("Error: Pointer to the list is a NULL pointer!\n");
        return;
    }

    if( isEmptyList(list) )
    {
        return;
    }

    pn = list->head;
    
    // remove nodes from the front
    while(pn != NULL)
    {
        pn = pn->next;
        popFront(list);
    }
}

struct Node *addAfter(struct List *list, struct Node *prevNode, void *data)
{
    struct Node *pn;

    if (list == NULL)
    {
        printf("Error: Pointer to the list is a NULL pointer!\n");
        return NULL;
    }

    if (prevNode == NULL)
    {
        // return head created by addFront
        return addFront(list, data);
    }
    
    // create node
    pn = (struct Node*)malloc(sizeof(struct Node));
    
    if (pn == NULL)
    {   
        printf("Failure: malloc returned NULL");
        return pn; 
    } 

    pn->data = data;
    pn->next = prevNode->next;
    prevNode->next = pn;

    // return created node
    return pn;

}


void reverseList(struct List *list)
{
    struct Node *prv = NULL;
    struct Node *cur;
    struct Node *nxt;

    if (list == NULL)
    {
        printf("Error: Pointer to the list is a NULL pointer!\n");
        return;
    }

    if( isEmptyList(list) )
    {
        return;
    }
    
    cur = list->head;

    // we make the current node's next point to prev
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }
    
    // assign new list head
    list->head = prv;

}

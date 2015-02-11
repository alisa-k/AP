/*
 * isort
 * CS 3157 Lab #2
 * Due: 9/29/14
 * Alisa Krivokapic (ak3533)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

/*
 * Main function
 */
int main()
{
    int size; 
    int *origArray;
    int *ascArray;
    int *descArray;

    // seed the random number generator with the current time in seconds
    srandom(time(NULL));
    
    printf("\nPlease enter the size of array: ");
    scanf("%d", &size);
    
    // create array of random ints and copy it to two additional arrays
    origArray = createRandomArray(size);
    ascArray = copyArray(origArray, size);
    descArray = copyArray(origArray, size);
    
    // sort ascArray in ascending order and descArray in descending order 
    sort_integer_array(ascArray, ascArray + size, 1);
    sort_integer_array(descArray, descArray + size, 0);
    
    // display all 3 arrays
    printf("\nOriginal Array:\n");
    printArray(origArray, size);
    printf("Ascending Array:\n");
    printArray(ascArray, size);
    printf("Descending Array:\n");
    printArray(descArray, size);

    // free the memory allocated for the arrays
    free(origArray);
    free(ascArray);
    free(descArray);

    return 0;
}

/*
 * Dynamically creates an array of integers and assigns it random values
 * Returns pointer to the created array 
 * The calling function is responsible for freeing the allocated memory
 */
int *createRandomArray(int size)
{
    int i;
    int *array;

    // dynamically allocate array of ints
    array = (int *) malloc(size * sizeof(int));
            
    // check return value of malloc()
    if (array == NULL)
    {   
        perror("malloc returned NULL");
        exit(1);
    }   
                
    // fill the array with random integers
    for (i = 0; i < size; i++)
    {   
        array[i] = random()%1000;
    }

    return array;
}

/*
 * Copies input array into new allocated array
 * Returns a pointer to that array
 * The calling function is responsible for freeing the allocated memory
 */
int *copyArray(int *array, int size)
{
    int i;
    int *copy;
    
    // dynamically allocate array of integers 
    copy = (int *) malloc(size * sizeof(int));

    // check return value of malloc()
    if (copy == NULL)
    {
        perror("malloc returned NULL");
        exit(1);
    }

    // copy the values of the original array
    for (i = 0; i < size; i++)
    {
        copy[i] = array[i];
    }

    return copy;
}

/*
 * Ascending comparison function passed assigned
 * to qsort()'s pointer function argument
 */
int cmpfuncAscending(const void *a, const void *b)
{
    if ( *((int *)a) < *((int *)b))
        return -1;
    else if (*((int *)a) > *((int *)b))
        return 1;
    else
        return 0;
}

/*
 * Descending comparison function passed assigned
 * to qsort()'s pointer function argument
 */
int cmpfuncDescending(const void *a, const void *b)
{
    return -(cmpfuncAscending(a, b));
}

/*
 * Sorts an array of integers in either ascending or 
 * descending order. 
 */
void sort_integer_array(int *begin, int *end, int ascending)
{
    if (ascending == 1)
        qsort(begin, end - begin, sizeof(int), cmpfuncAscending);
    else if (ascending == 0)
        qsort(begin, end - begin, sizeof(int), cmpfuncDescending);
    else
        printf("\nError.\n");
}

/*
 * Prints array of integers
 */
void printArray(int *array, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}


#ifndef __SORT_H__
#define __SORT_H__

int *createRandomArray(int);
int *copyArray(int *, int);
int cmpfuncAscending(const void *, const void *); 
int cmpfuncDescending(const void *, const void *); 
void sort_integer_array(int *, int *, int);
void printArray(int *, int);

#endif

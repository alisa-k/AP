/*************************************************************************
 ***  Alisa Krivokapic
 ***  UNI: ak3533
 ***  CS3157 Lab 2
 ***  9-29-2014
 *************************************************************************/
 
***************************************************************************
                                    PART 1
***************************************************************************

isort is a C program that:
- gets size of array from user
- creates array of integers by dynamically allocating it & filling it
  with randomly generated integer values using the C random() function
- makes a copy of the array and sorts it in ascending order 
- makes a second copy of the array and sorts it in descending order
- prints all arrays (original array, ascending array, descending array)

Solution Details: everything works as expected. 

* sort.c   : - implemented createArray() function that creates original
               array and assigns it random integer values
             - implemented copyArray() function which creates a copy
               of the array passed in
             - calling function frees allocated memory for copyArray()
               and createArray() functions
             - used the qsort() C library function to sort the arrays 
               in ascending and descending order. 
               (read section 5.11 in K&R about pointers to functions)
               implemented comparison functions cmpfuncAscending() and
               cmpfuncDescending() to be used for qsort()

* Makefile : - modified the template provided by professor Jae Lee
             - introduced a make variable TARGET & assigned the name
               of the program to it (isort)

* valgrind : 

==21528== Memcheck, a memory error detector
==21528== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al. 
==21528== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==21528== Command: ./isort
==21528== 

Please enter the size of array: 
Original Array:
813 243 893 834 62  

Ascending Array:
62 243 813 834 893 

Descending Array:
893 834 813 243 62  

==21528== 
==21528== HEAP SUMMARY:
==21528==     in use at exit: 0 bytes in 0 blocks
==21528==   total heap usage: 3 allocs, 3 frees, 60 bytes allocated
==21528== 
==21528== All heap blocks were freed -- no leaks are possible
==21528== 
==21528== For counts of detected and suppressed errors, rerun with: -v
==21528== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

***************************************************************************
                                    PART 2
***************************************************************************

twecho is a C program that:
- takes words as command line arguments and prints each word twice : 
- once as is, and once all capitalized.

Solution Details: everything works as expected.

* twecho.c : - implemented duplicateArgs() function that makes a copy
               of the memory structure shown in the K&R book on p.115
               created array of char pointers using malloc() and then 
               called malloc() for each element of that array to
               allocate the memory for the individual strings
             - implemented freeDuplicatedArgs() to free all of the 
               previously dynamically allocated memory

* Makefile : - modified the template provided by professor Jae Lee 
             - introduced a make variable TARGET & assigned the name
               of the program to it (twecho)

* valgrind :

==22030== Memcheck, a memory error detector
==22030== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==22030== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==22030== Command: ./twecho hello world alisa
==22030== 
hello HELLO
world WORLD
alisa ALISA
==22030== 
==22030== HEAP SUMMARY:
==22030==     in use at exit: 0 bytes in 0 blocks
==22030==   total heap usage: 5 allocs, 5 frees, 67 bytes allocated
==22030== 
==22030== All heap blocks were freed -- no leaks are possible
==22030== 
==22030== For counts of detected and suppressed errors, rerun with: -v
==22030== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

//////////////////////////////////////////////////////////////////////////
//                                                                                                                  
// Alisa Krivokapic
// UNI: ak3533
// CS 3157, lab #3, October 3, 2014
//
//////////////////////////////////////////////////////////////////////////
//
//
//  Part1 requirements:
//  
//  a) implement a generic singly linked list that can hold any data type
//     * the interface is provided in the header file mylist.h
//     * test driver program is provided with mylist-test.c
//     * produces output that matches the output in the provided
//       text file mylist-test-output.txt'
//     * Makefile to build mylist-test
//     * valgrind output has to be included in README.txt
//                              
//  b) modify Makefile to produce a static library libmylist.a and the test
//     program must link to that library
//     * based on linked list implementation (a)
//     * based on provided test program, mylist-test
//                            
//
//
//  Solution details: worked as expected    
//  
//  a) * used isEmptyList() function to handle the empty list case
//     * implemented reverseList() by assigning the address of previous
//       node to current node's next
//
//  b) Makefile:
//
//     - created libmylist.a using following steps:
//       * compiled mylist.c into object file mylist.o 
//       * used "av rc libmylist.a mylist.o" to create the static library 
//         libmylist.a 
//       * used "ranlib libmylist.a" to create index inside the library
//           
//     - built target set by TARGET = mylist-test using following steps:
//       * compiled mylist-test.c into mylist-test.o
//       * linked TARGET = mylist-test to the STATICLIB = libmylist.a
//
//
//
//
//  Part2 requirements:     
//  
//  - use libmylist.a produced in part1 to write a program 'revecho'
//    * revecho prints out the command line arguments in reverse order
//    * it looks for the word "dude" among the command line arguments
//      passed and reports if it was found or not
//    * Makefile: 'revecho' has to link to the third party static library
//      myliblist.a
//    * valgrind output has to be included in README.txt
//
//  Solution details: worked as expected
//
//    * implemented printData() and passed printData to traverseList() 
//      to print out the command line arguments
//    * used findNode() to find "dude" and passed strcmp to it by
//      casting it to the correct function pointer type
//    * modified Makefile to use predefined variables LDFLAGS and INCLUDES
//      to specify the path for the library libmylist.a and file mylist.h 
//      using "-L" and "-I" option
//                                          

PART 1 Valgrind Output


==31108== Memcheck, a memory error detector
==31108== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==31108== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==31108== Command: ./mylist-test
==31108== 
testing addFront(): 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing flipSignDouble(): -9.0 -8.0 -7.0 -6.0 -5.0 -4.0 -3.0 -2.0 -1.0 
testing flipSignDouble() again: 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing findNode(): OK
popped 9.0, the rest is: [ 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 8.0, the rest is: [ 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 7.0, the rest is: [ 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 6.0, the rest is: [ 5.0 4.0 3.0 2.0 1.0 ]
popped 5.0, the rest is: [ 4.0 3.0 2.0 1.0 ]
popped 4.0, the rest is: [ 3.0 2.0 1.0 ]
popped 3.0, the rest is: [ 2.0 1.0 ]
popped 2.0, the rest is: [ 1.0 ]
popped 1.0, the rest is: [ ]
testing addAfter(): 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 
popped 1.0, and reversed the rest: [ 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 ]
popped 9.0, and reversed the rest: [ 2.0 3.0 4.0 5.0 6.0 7.0 8.0 ]
popped 2.0, and reversed the rest: [ 8.0 7.0 6.0 5.0 4.0 3.0 ]
popped 8.0, and reversed the rest: [ 3.0 4.0 5.0 6.0 7.0 ]
popped 3.0, and reversed the rest: [ 7.0 6.0 5.0 4.0 ]
popped 7.0, and reversed the rest: [ 4.0 5.0 6.0 ]
popped 4.0, and reversed the rest: [ 6.0 5.0 ]
popped 6.0, and reversed the rest: [ 5.0 ]
popped 5.0, and reversed the rest: [ ]
==31108== 
==31108== HEAP SUMMARY:
==31108==     in use at exit: 0 bytes in 0 blocks
==31108==   total heap usage: 18 allocs, 18 frees, 288 bytes allocated
==31108== 
==31108== All heap blocks were freed -- no leaks are possible
==31108== 
==31108== For counts of detected and suppressed errors, rerun with: -v
==31108== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)


PART 2 Valgrind Output 


==13285== Memcheck, a memory error detector
==13285== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==13285== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==13285== Command: ./revecho hello world dude
==13285== 
dude
world
hello

dude found
==13285== 
==13285== HEAP SUMMARY:
==13285==     in use at exit: 0 bytes in 0 blocks
==13285==   total heap usage: 3 allocs, 3 frees, 48 bytes allocated
==13285== 
==13285== All heap blocks were freed -- no leaks are possible
==13285== 
==13285== For counts of detected and suppressed errors, rerun with: -v
==13285== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

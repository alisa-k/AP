**********************************************************************************************************************
** Alisa Krivokapic
** UNI: ak3533
** CS 3157, lab4, 10/16/14
**********************************************************************************************************************
**
**  Part1: 
**                      a)   Requirements:
**
**                          * Use mdb-add-cs3157 program which inserts a record into the mdb-cs3157 database file
**                           and insert a couple of records. List the name and message pairs that you have inserted. 
**                          
**
**                           Solution details:
**
**                          * inserted: 141: {^___^} said {testing hi}
**
**
**



**
**  Option I            b)  mdb-lookup program
**   
**                         * mdb-lookup takes the database file name as the command line argument
**                         * read all the records from the database file into memory
**                         * keep the records in a linked list using mylist as a third party library
**                           located in lab3/part1 directory
**                         * the records have to be in the same order as they are in the database file
**                         * read the search string from the keyboard (assume input line will never
**                           exceed certain large number of characters (I used 1000)
**                         * mdb-lookup should truncate the search string at 5 characters (consider
**                           input less than 5 characters & input that contains non-printable characters
**                           after truncation)
**                         * search both name and msg fields of the record
**                         * print the record numbers
**                         * free the allocated memory
**                         * close the file as soon as db loaded
**                         * error handling
**
**
**                          Solution details: works as expected
**
**                         * function loadmdb()
**                           - returns 0 in case of success, 1 in case of error
**                         * function mdblookup()
**                           - returns 1 in case of input error, but user can continue to search
**                           - returns 0 in case of success, user can continue to search
**                           - returns 2 if Ctrl-D is pressed
**                           - Ctrl-D has to be pressed twice to simulate end of file if it is
**                             pressed after some characters are already entered. Function fgets()
**                             doesn't return 0 in that case, so feof() and ferror() (if error happens
**                             after some characters already entered) have to be invoked after fgets().
**                           - it is assumed that an input line will never exceed 1000 characters


**
**  Valgind output: 

==20136== Memcheck, a memory error detector
==20136== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==20136== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==20136== Command: ./mdb-lookup my-mdb
==20136== 
lookup :  1: {alisa} said {testing hi}
 2: {* *} said {alisa krivokapic}

lookup :  2: {* *} said {alisa krivokapic}

lookup : ==20136== 
==20136== HEAP SUMMARY:
==20136==     in use at exit: 0 bytes in 0 blocks
==20136==   total heap usage: 8 allocs, 8 frees, 776 bytes allocated
==20136== 
==20136== All heap blocks were freed -- no leaks are possible
==20136== 
==20136== For counts of detected and suppressed errors, rerun with: -v
==20136== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

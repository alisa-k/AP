------------------------------------------------------------------------------
Alisa Krivokapic (ak3533)
CS W3157, Lab #1, 9-17-14
------------------------------------------------------------------------------

    Part 1. C Program that:

            * reads 2 positive integers from a user
            * prints the average of those numbers
            * determines whether each of those numbers is prime
            * determines if the two numbers are coprime
              (using the Euclidean GCD algorithm)
    
            Solution Details:    Worked as expected. 

            * GCD algorithm      - function int gcd(int, int)
                                 - implemented the function as a recursion
                                 - also handled case of non-positive input

            * Makefile           - modified the template from lecture notes
                                   to specify the required compiling and
                                   linking options and specify dependencies
                                 - provided "clean" target
                                 - introduced TARGET variable for executable

    Part 2. C program that: reads a signed decimal integer and

            * prints the number as a signed decimal
            * prints the number as an unsigned decimal
            * prints the number in hexadecimal representation
            * prints the number in its binary representation

            Solution Details:    Worked as expected.
            
            * printBinary        - function void printBinary(int, int)
                                 - used bitwise operators to detect if 
                                   bit was 1 or 0 at a specified position
                                   in binary representation of a number

            * Makefile           - modified the template from lecture notes
                                   to specify the required compiling and
                                   linking options and specify dependencies
                                 - provided "clean" target
                                 - introduced TARGET variable for executable

            * Prog. Output       - made sure spacing was correct by using
                                   '*' as variable width specification in
                                   printf


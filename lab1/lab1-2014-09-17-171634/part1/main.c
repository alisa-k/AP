#include <stdio.h>
#include "prime.h"
#include "gcd.h"

int main()
{
    int a, b;
    float avg;
    
    // Ask user for input
    printf("\nPlease enter the first integer: ");
    scanf("%d", &a);
    printf("\nPlease enter the second integer: ");
    scanf("%d", &b);
    printf("\nYou typed in %d and %d\n", a, b);
    
    // Print average
    avg = (a + b)/2.0f;
    printf("The average is: %f\n", avg);
    
    // Prints whether or not numbers entered are prime
    if (isPrime(a) == 1)
        printf("%d is prime.\n", a);
    else
        printf("%d is not prime.\n", a);
    if (isPrime(b) == 1)
        printf("%d is prime.\n", b);
    else
        printf("%d is not prime.\n", b);
    
    // If the GCD is 1, the numbers are relatively prime.
    if(gcd(a, b) == 1)
        printf("The numbers %d and %d are relatively prime.\n\n", a, b);
    else
        printf("The numbers %d and %d are not relatively prime.\n\n", a, b);
    
    return 0;
}

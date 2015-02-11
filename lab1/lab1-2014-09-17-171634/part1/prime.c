#include "prime.h"

// determines if a number is prime
// returns 1 if true, 0 if false
int isPrime(int x)
{
    int i;
    
    // 1 is not prime
    if (x == 1)
        return 0;
    
    for (i = 2; i < x; i++)
    {
        if (x%i == 0)
            return 0;
    }
    return 1;
}

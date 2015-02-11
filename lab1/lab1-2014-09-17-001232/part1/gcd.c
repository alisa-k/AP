#include "gcd.h"

// calculates GCD using Euclidean algorithm
int gcd(int a, int b)
{
    int r;      // the remainder when a divided by b
    
    // gcd(0, 0) = 0 by definition
    if(a == 0 && b == 0)
        return 0;

    // if either a or b is negative, the gcd will be
    // the same as that of their positive counterparts
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;

    // let a >= b
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Euclidean algorithm:
    // assume a >= 0, b >=0
    // gcd(a, b) = a if b = 0
    // gcd(b, r) if b != 0.

    if(b != 0)
    {
        r = a%b;
    }

    // call gcd recursively
    return b == 0 ? a : gcd(b, r);
}


#include <stdio.h>
#include <string.h>

void printBinary(int);

int main()
{
    int x;
    
    // calculates width of longest phrase in order to 
    // achieve the correct spacing in the display
    int typeWidth = (int) (strlen("unsigned dec:")) * (-1);

    // gets input from user
    scanf("%d", &x);
    
    // displays x as the specified type
    printf("%*s %d\n", typeWidth, "signed dec:" , x);
    printf("%*s %u\n", typeWidth, "unsigned dec:", x);
    printf("%*s %x\n", typeWidth, "hex:", x);
    printf("%*s ", typeWidth, "binary:");
    printBinary(x);
    
    return 0;
}

// prints binary representation of an integer
void printBinary(int x)
{
    int bitCount = sizeof(x) * 8;             // number of bits in binary rep.
    unsigned int mask = 1 << (bitCount - 1);  // has exactly one 1-bit in bin rep. 
    int pos = bitCount - 1;                   // current bit position
    
    while (pos >= 0)
    {
        // determines bit at position pos
        if (mask & x)
            printf("%c", '1');
        else
            printf("%c", '0');
        
        // makes space after every 4 bits
        if (pos % 4 == 0)
            printf(" ");
        
        pos--;
        mask >>= 1;
    }
    printf("\n");
}

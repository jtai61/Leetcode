#include "bitwise.h"

unsigned char count_bit1(unsigned char byte)
{
    unsigned char count = 0;

    while (byte)
    {
        if (byte & 1)
        {
            count++;
        }

        byte >>= 1;
    }

    return count;
}

/* print binary number */
void dec_to_bin(unsigned char num)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

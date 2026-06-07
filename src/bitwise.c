#include "bitwise.h"

u32 CountBitOne(u32 num)
{
    u32 count = 0;

    while (num)
    {
        count++;
        num &= (num - 1);
    }
    
    return count;
}

int Find_MSB(u8 num)
{
    if (num == 0)
    {
        return -1;
    }

    int count = -1;

    while (num)
    {
        count++;
        num >>= 1;
    }

    return count;
}

void XOR_swap(u8 *a, u8 *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

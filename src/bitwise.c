#include "bitwise.h"

/* Method 1 */
unsigned int hamming_weight_v1(unsigned int num)
{
    unsigned int count = 0;

    while (num)
    {
        if (num & 1)
        {
            count++;
        }
        num >>= 1;
    }
    
    return count;
}

/* Method 2 */
unsigned int hamming_weight_v2(unsigned int num)
{
    unsigned int count = 0;

    while (num)
    {
        num &= (num - 1);
        count++;
    }
    
    return count;
}

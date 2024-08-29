#include <stdio.h>

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

int func(int x)
{
    int num = 0;

    while (x)
    {
        num++;
        x = x & (x - 1);
    }
    
    return num;
}

/* 1 + 2 + 4 + 7 + ... + 106 */
unsigned int sum(void)
{
    unsigned int sum = 0;

    for (int i = 1, j = 1; i <= 106; i += j, j++)
    {
        sum += i;
    }
    
    return sum;
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

int main()
{
    convert_binary(200);


    return 0;
}
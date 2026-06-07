#include "string.h"

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int string_length(char *src)
{
    int count = 0;
    char *ptr = src;

    while (*ptr != '\0')
    {
        count++;
        ptr++;
    }
    
    return count;
}

void string_reverse(char *src)
{
    int len = strlen(src);

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        swap(&src[i], &src[j]);
    }
}

char *string_concat(char *src1, char *src2)
{
    int len1 = strlen(src1), len2 = strlen(src2);
    char *dest = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    for (int i = 0; i < len1; i++)
    {
        dest[i] = src1[i];
    }

    for (int j = 0; j < len2; j++)
    {
        dest[len1 + j] = src2[j];
    }
    
    dest[len1 + len2] = '\0';

    return dest;
}

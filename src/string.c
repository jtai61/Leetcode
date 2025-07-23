#include "string.h"

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int string_length(char *str)
{
    int i, count;

    for (i = 0, count = 0; str[i] != '\0'; i++, count++)
        ;

    return count;
}

void string_reverse(char *str)
{
    int len = string_length(str);

    for (int i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        swap(&str[i], &str[j]);
    }
}

void string_concat(char *str1, char *str2, char *dest)
{
    int str1_len = string_length(str1);
    int str2_len = string_length(str2);

    for (int i = 0, j = 0; i < str1_len, j < str2_len; i++, j++)
    {
        dest[i] = str1[i];
        dest[str1_len + j] = str2[j];
    }
    dest[str1_len + str2_len] = '\0';
}

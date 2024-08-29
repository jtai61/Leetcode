#include <stdio.h>

/*
    *****
    *   *
    *   *
    *   *
    *****
*/
void square(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");

    for (i = 0; i < n - 2; i++)
    {
        printf("*");
        for (j = 0; j < n - 2; j++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");
}

/*
        *
       ***
      *****
     *******
      *****
       ***
        *
*/
void diamond(int n)
{
    int i, j;
    int tmp = n;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1) - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j < 2 * (i + 1) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (i = 0; i < 2 * n - 1; i++)
    {
        printf("*");
    }
    printf("\n");
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            printf(" ");
        }
        for (j = 0; j < 2 * (tmp - 1) - 1; j++)
        {
            printf("*");
        }
        tmp--;
        printf("\n");
    }
}

/*
        *
       ***
      *****
     *******
*/
void triangle(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - (i + 1); j++)
        {
            printf(" ");
        }
        for (j = 0; j < 2 * (i + 1) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    diamond(5);


    return 0;
}

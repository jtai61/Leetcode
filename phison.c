#include <stdio.h>

struct A
{
    int a;
    short b;
    int c;
    char d;
};

// 給一個int a[20]已排序的陣列，請寫一個function(a, size)能印出0~500的數字，且不包含a陣列內的元素，請用最少的時間和空間複雜度完成
void func_1(int *arr, int size)
{
    int *p = arr;

    for (int i = 0; i <= size; i++)
    {
        if (*p == i)
        {
            p++;
        }
        else
        {
            printf("%d\n", i);
        }
    }
}

// 給一個int a[20]已排序的陣列，請寫一個function(a, size, b) 能依照參數b(b = 0~4)別印出該區間的數字，且不包含a陣列內的元素
// 例如 b=0, 印出0~99, b = 1, 印出100~199
void func_2(int *arr, int size, int b)
{
    int *p, i;

    for (p = arr; *p < b * 100; p++)
        ;

    for (i = b * 100; i < (b + 1) * 100; i++)
    {
        if (*p == i)
        {
            p++;
        }
        else
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    // int a[20] = { 12, 15, 22, 37, 68, 83, 115, 174, 196, 201, 224, 275, 300, 316, 333, 367, 412, 455, 488, 500 };

    // // func_1(a, 500);
    // func_2(a, 500, 4);
    int a[5] = {1, 2, 3, 4, 5};
    int *p = (int *)(&a + 1);

    return 0;
}
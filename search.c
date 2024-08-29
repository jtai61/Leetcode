#include <stdio.h>

/* iterative binary search non-duplicate elements */
int Iterative_Binary_Search(int *data, int length, int target)
{
    int left = 0;
    int right = length - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (target < data[mid])
        {
            right = mid - 1;
        }
        else if (target > data[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;     // found
        }
    }

    return -1;  // not found
}

/* recursive binary search non-duplicate elements */
int Recursive_Binary_Search(int *data, int left, int right, int target)
{
    int mid = (left + right) / 2;

    if (left > right)
    {
        return -1;      // not found
    }
    else
    {
        if (target < data[mid])
        {
            return Recursive_Binary_Search(data, left, mid - 1, target);
        }
        else if (target > data[mid])
        {
            return Recursive_Binary_Search(data, mid + 1, right, target);
        }
        else
        {
            return mid;     // found
        }
    }
}

int main()
{
    int a[10] = { -3, 1, 4, 7, 10, 14, 16, 20, 25, 26};

    printf("search result: %d\n", Iterative_Binary_Search(a, 10, 4));
    printf("search result: %d\n", Recursive_Binary_Search(a, 0, 9, 30));


    return 0;
}

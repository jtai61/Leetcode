#include "search.h"

/* Iterative binary search non-duplicate elements */
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

/* Recursive binary search non-duplicate elements */
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

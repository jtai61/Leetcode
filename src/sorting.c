#include "sorting.h"

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int *data, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%2d ", data[i]);
    }
    printf("\n");
}

int partition(int *data, int left, int right)
{
    int pivot = data[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            swap(&data[i], &data[j]);
        }
    }

    swap(&data[i + 1], &data[right]);

    return (i + 1);
}

void QuickSort(int *data, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(data, left, right);

        QuickSort(data, left, pivot - 1);
        QuickSort(data, pivot + 1, right);
    }
}

void BubbleSort(int *data, int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}

void merge(int *data, int left, int mid, int right)
{
    int nL = mid - left + 1;    // length of data[left:mid]
    int nR = right - mid;

    // 建立臨時陣列
    int *L = (int *)malloc(nL * sizeof(int));
    int *R = (int *)malloc(nR * sizeof(int));

    int i, j, k;

    // 將數據複製到臨時陣列 L[] 和 R[]
    for (i = 0; i < nL; i++)
        L[i] = data[left + i];
    for (j = 0; j < nR; j++)
        R[j] = data[mid + 1 + j];

    i = 0;      // 初始位置的索引 L[]
    j = 0;      // 初始位置的索引 R[]
    k = left;   // 初始位置的索引 data[]

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    // 複製 L[] 的剩餘元素（如果有的話）
    while (i < nL)
    {
        data[k] = L[i];
        i++;
        k++;
    }

    // 複製 R[] 的剩餘元素（如果有的話）
    while (j < nR)
    {
        data[k] = R[j];
        j++;
        k++;
    }

    // 釋放臨時陣列的記憶體
    free(L);
    free(R);
}

/* Recursive MergeSort */
void MergeSort(int *data, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        MergeSort(data, left, mid);
        MergeSort(data, mid + 1, right);

        merge(data, left, mid, right);
    }
}

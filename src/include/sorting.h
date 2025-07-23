#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void print_array(int *, int);
int partition(int *, int, int);
void QuickSort(int *, int, int);
void BubbleSort(int *, int);
void merge(int *, int, int, int);
void MergeSort(int *, int, int);

#endif
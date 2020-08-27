/*
  11.7.c
  <TBC>
  Created by Chan Ho Park on <20200720>.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void selection_sort(int*, int);

void swap(int*, int, int);

int main()
{
    int arr[] = { 51, 21, 42, 67, 48, 56, 23, 34 };
    selection_sort(arr, sizeof(arr));

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);

    return 0;
}

void selection_sort(int* arr, int n)
{
    int min_idx, size = n / sizeof(int);

    for (int bar = 0; bar < size - 1; bar++)
    {
        min_idx = bar;

        for (int i = bar + 1; i < size; i++)
        {
            if (arr[min_idx] > arr[i])
                min_idx = i;
        }
        
        swap(arr, min_idx, bar);

    }

}

void swap(int* arr, int a, int b)
{
    if (a != b)
    {
        arr[a] += arr[b];
        arr[b] = arr[a] - arr[b];
        arr[a] -= arr[b];
    }
}

/**(arr + min_idx) += *(arr + bar);
        *(arr + bar) = *(arr + min_idx) - *(arr + bar);
        *(arr + min_idx) -= *(arr + bar)*/
/*
  11.8.c
  <TBC>
  Created by Chan Ho Park on <20200721>.
*/

#include <stdio.h>
#include <string.h>

void selection_sort(char* [], int);
void swap(char* [], int, int);
void printStringArray(char* [], int);

int main()
{
    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);
    

    printStringArray(arr, n);

    printf("\n\n");

    selection_sort(arr, n);
    printStringArray(arr, n);


    return 0;
}

void selection_sort(char* arr[], int size)
{
    int min_idx;

    for (int bar = 0; bar < size - 1; bar++)
    {
        min_idx = bar;

        for (int i = bar + 1; i < size; i++)
        {
            if (strcmp(arr[min_idx], arr[i]) == 1)
                min_idx = i;
        }

        swap(arr, min_idx, bar);

    }

}

void swap(char* arr[], int a, int b)
{
    if (a != b)
    {
        char* temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}

void printStringArray(char* arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        char* temp = arr[i];

        while (putchar(*temp) != '\0') (temp)++;

        printf("\n");
    }
}

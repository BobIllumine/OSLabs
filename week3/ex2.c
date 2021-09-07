//
// Created by hered on 01.09.2021.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(size_t n, int arr[])
{
    for(int i = 0; i < n - 1; ++i)
        for(int j = 0; j < n - i - 1; ++j)
            if(arr[j] > arr[j + 1])
                swap(arr + j, arr + j + 1);

}

int main () {
    printf("Insert the number of elements in array: \n");
    static size_t n;
    scanf("%d", &n);
    printf("Insert the elements of array: \n");
    int arr[n];
    for(int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    bubble_sort(n, arr);
    printf("Sorted array: \n");
    for(int i = 0; i < 5; ++i)
        printf("%d ", arr[i]);
    return 0;
}
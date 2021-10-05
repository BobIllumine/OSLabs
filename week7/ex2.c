//
// Created by hered on 30.09.2021.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    int *arr = (int*)calloc(n, sizeof(int));
    printf("arr[%d] = %d\n", 0, 0);
    for(int i = 1; i < n; ++i) {
        arr[i] = arr[i - 1] + 1;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
}

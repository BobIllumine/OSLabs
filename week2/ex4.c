//
// Created by hered on 25.08.2021.
//
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a, b;
    printf("Enter two numbers to swap:\n");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Swapped numbers: %d %d", a, b);
}

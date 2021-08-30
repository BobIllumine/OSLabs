//
// Created by hered on 25.08.2021.
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, cnt = 1;
    printf("Enter a number, the height of a triangle:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < ((2 * n - 1) - cnt) / 2; ++j)
            printf(" ");
        for(int j = 0; j < cnt; ++j)
            printf("*");
        for(int j = 0; j < ((2 * n - 1) - cnt) / 2; ++j)
            printf(" ");
        printf("\n");
        cnt += 2;
    }
}

//
// Created by hered on 25.08.2021.
//
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("Size of int: %llu, max value: %d\n", sizeof a, a);
    printf("Size of float: %llu, max value: %f\n", sizeof b, b);
    printf("Size of double: %llu, max value: %f\n", sizeof c, c);
}

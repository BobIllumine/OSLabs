//
// Created by hered on 30.09.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void* realloc_c(void *ptr, size_t size) {
    void *new_ptr = malloc(size);
    if(ptr != NULL)
        memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

int main() {
    float *arr = (float*) calloc(5, sizeof(float));
    for(int i = 0; i < 5; ++i)
        arr[i] = i * 0.01, printf("%f ", arr[i]);
    printf("\n");
    arr = (float *) realloc_c(arr, 5 * sizeof(float ));
    for(int i = 0; i < 10; ++i)
        printf("%f ", arr[i]);
    return 0;
}
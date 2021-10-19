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
    int *arr = (int*) calloc(5, sizeof(int));
    for(int i = 0; i < 5; ++i)
        arr[i] = i + 1, printf("%d ", arr[i]);
    printf("\n");
    realloc_c(arr, 0);
    for(int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}
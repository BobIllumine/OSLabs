//
// Created by hered on 30.09.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void* realloc_c(void *ptr, size_t size) {
    void *new_ptr = malloc(size);
    printf("%zu %zu\n", size, sizeof(ptr));
    size_t copy_size = (size < sizeof(ptr) ? size : sizeof(ptr));
    memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}

int main() {
    int *arr = (int*) calloc(5, sizeof(int));
    for(int i = 0; i < 5; ++i)
        arr[i] = i, printf("%d ", arr[i]);
    printf("\n");
    arr = (int*) realloc_c(arr, 10 * sizeof(int));
    for(int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);
    return 0;
}
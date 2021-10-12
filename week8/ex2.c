//
// Created by hered on 30.09.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <string.h>
#include <time.h>


int main() {
    clock_t start = clock();
    while((clock() - start) / CLOCKS_PER_SEC <= 10) {
        void *junk = malloc((size_t)1e7);
        memset(junk, 0, (size_t)1e7);
        sleep(1);
    }
    // Allocated memory is not released, so it causes a memory leak
    // In 10 seconds, it fills up to 100Mb of RAM
    // It is not so crucial for modern hardware with gigabytes of RAM
    // but it still can deal some damage
    return 0;
}
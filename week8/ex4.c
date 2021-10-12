
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
        struct rusage use;
        getrusage(RUSAGE_SELF, &use);
        printf("Memory usage: %d\n", use.ru_maxrss);
        sleep(1);
    }
    return 0;
}
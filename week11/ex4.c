//
// Created by hered on 02.11.2021.
//
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int src = open("../week11/ex1.txt", O_RDONLY);

    struct stat fstat;
    stat("../week11/ex1.txt", &fstat);
    int fsize = fstat.st_size;

    char *src_map = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, src, 0);

    int dest = open("../week11/ex1.memcpy.txt", O_RDWR);

    ftruncate(dest, fsize);

    char *dest_map = mmap(NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);

    memcpy(dest_map, src_map, fsize);

    msync(dest_map, fsize, MS_SYNC);

    munmap(src_map, fsize);
    munmap(dest_map, fsize);

    close(src);
    close(dest);

    return 0;
}


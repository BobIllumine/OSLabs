//
// Created by hered on 02.11.2021.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define STRING_SIZE 18

int main()
{
    int file = open("../week11/ex1.txt", O_RDWR);
    lseek(file, STRING_SIZE, SEEK_SET);
    char *map = mmap(0, STRING_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    char str[STRING_SIZE+1] = "This is a nice day";
    memcpy(map, str, STRING_SIZE);
    msync(map, STRING_SIZE, MS_SYNC);
    munmap(map, STRING_SIZE);
    close(file);
    return 0;
}
//
// Created by hered on 02.11.2021.
//
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define STRING_SIZE 5

int main()
{
    char str[STRING_SIZE] = "Hello";

    setvbuf(stdout, NULL, _IOLBF, BUFSIZ);

    for(int i = 0; i < STRING_SIZE; ++i) {
        printf("%c", str[i]);
        sleep(1);
    }

    return 0;
}


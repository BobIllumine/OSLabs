//
// Created by hered on 30.09.2021.
//

#include <stdlib.h>
#include <stdio.h>

int main() {
    char **s = (char**) malloc(sizeof *s);
    char foo[] = "Hello World!";
    *s = foo;
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %c\n", *s[0]);
    free(s);
    return 0;
}
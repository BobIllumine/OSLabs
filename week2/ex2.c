//
// Created by hered on 25.08.2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <zlib.h>

char *readline(const char *line)
{
    size_t len = 0;
    char *res = malloc(len + 1);
    char c;
    while((c = getchar()) != EOF && c != '\n')
    {
        res[len++] = c;
        res = realloc(res, len + 1);
    }
    res[len++] = '\0';
    return realloc(res, sizeof(*res) * len);
}

int main()
{
    char *in = NULL;
    printf("Enter a string: \n");
    char *s = readline(in);
    strrev(s);
    printf("Reversed string: %s", s);
    free(s);
}

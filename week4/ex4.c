#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

void next() {
        char *command = (char*)calloc(0, 256);
        size_t len = 256;
        getline(&command, &len, stdin);
        command[strlen(command) - 1] = '\0';
        if(strcmp(command, "exit") == 0)
                return;
        int splits = 0;
        for(int i = 0; i < strlen(command); ++i)
                if(command[i] == ' ')
                        ++splits;
        char *args[splits + 2];
        for(int l = 0, r = 0, ptr = 0; r < strlen(command); ++r) {
                if(command[r] == ' ' || r == strlen(command) - 1) {
                        r += (r == strlen(command) - 1 ? 1 : 0);
                        args[ptr] = (char*)calloc(0, (r - l) + 1);
                        for(int i = 0; i < (r - l); ++i)
                                args[ptr][i] = command[l + i];   
                        ++ptr;
                        l = r + 1;
                        continue;
                }

        }
        free(command);
        args[splits + 1] = (char*)0;
        pid_t process = fork();
        if(process == 0) {
              execvp(args[0], args);
              for(int i = 0; i < splits + 1; ++i)
                     free(args[i]);
              return;
        }
        else
                next();
}

int main(int argc, char **argv) {
        printf("[Enter 'exit' to finish program]\n");
        next();

}

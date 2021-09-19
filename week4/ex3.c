#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	printf("[Enter 'exit' to finish the program]\n");
       	size_t len = 8;
	char *command;
       	getline(&command, &len, stdin);
	command[strlen(command) - 1] = '\0';	
	while(strcmp(command, "exit") != 0) {
		system(command);
		getline(&command, &len, stdin);
	}	
	return 0;
}

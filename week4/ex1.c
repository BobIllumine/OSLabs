#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
	int n;
	pid_t p = fork();
	n = getpid();
	if(p == 0)
		printf("Hello from child %d\n", n);
	else
		printf("Hello from parent %d\n", n);
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
	for(int i = 0; i < 3; ++i) {
		fork();
	//	printf("Hello from %d\n", getpid());
		sleep(5);
	//	printf("Bye from %d\n", getpid());
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <string.h>

pthread_t threads[2] = {NULL, NULL}; // producer - consumer
int state[2] = {0, 0}; // 0 - off, 1 - on
int t_id[2] = {0, 1};
char *buffer;


void sleep(size_t id) {
	state[id] = 0;
}

void awake(size_t id) {
	state[id] = 1;
}

void tick(int id) {
	if(id == 0 && state[id] == 1) { // producer case: awake
		if(strlen(buffer) == 10) {
			printf("buffer is full uwu, back to sleep\n");
			sleep(id);
		}
		else {
			buffer = (char*)calloc(0, sizeof(char) * 11);
			for(int i = 0; i < 10; ++i)
				buffer[i] = (rand() % 26) + 'a';
	    		printf("buffer now contains '%s' owo\n", buffer);		
		}
		awake(1);
	}
	else if(id == 1 && state[id] == 1) { // consumer case: awake
		if(strlen(buffer) == 0) {
			printf("buffer is empty uwu, back to sleep\n");
			sleep(id);
		}
		else {
			printf("there was '%s' in the buffer, owo\n", buffer);
			free(buffer);
		}
		awake(0);
	}
}

void* on_create(void *t_id) {
	int id = *((int*)t_id);
	printf("Ohayo!~ Thread %d is awake owo\n", id);
	awake(id);
	for(;;)
		tick(id);
}


int main(int argc, char **argv) {
	srand(time(NULL));
	buffer = (char*)malloc(0);
	pthread_create(&threads[0], NULL, on_create, &t_id[0]);
	pthread_create(&threads[1], NULL, on_create, &t_id[1]);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	return 0;
}

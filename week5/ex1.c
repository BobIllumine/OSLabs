#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

#define N 10

void *thread_hello(void *arg) {
	printf("Hello from thread %d!\n", pthread_self());
}

int main(int argc, char **argv) {
	pthread_t threads[N];
	for(int i = 0; i < N; ++i) {
		if(!pthread_create(&threads[i], NULL, thread_hello, NULL))
			printf("Thread %d created!\n", threads[i]);
		printf("Thread %d exits!\n", threads[i]);
		pthread_join(threads[i], NULL);
	}
	return 0;
}

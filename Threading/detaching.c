#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <strings.h>

// Declare the method so that you can keep the main function at the top and
// instantiate it later.
void *producer(void *arg);
pthread_mutex_t lock;

int main() {
	pthread_t producer_thread;
	pthread_mutex_init(&lock, NULL);
	int *ptr = malloc(sizeof(int));
	int *ptr_ptr = ptr;

	printf("prt = %d\n", *ptr);

	free(ptr);

	printf("prt = %d\n", *ptr);
	printf("prt_ptr = %d\n", *ptr_ptr);

	printf("Main thread starting with id: %lu\n", &producer_thread);

	if (pthread_create(&producer_thread, NULL, producer, "Hello from main.")) {
		perror("pthread_create() error");
		exit(1);
	}

	pthread_detach(producer_thread);

	printf("detatched from producer.\n");

	pthread_mutex_lock(&lock);
	printf("Main thread exiting\n");
	pthread_mutex_unlock(&lock);

	return 0;
}

// Instantiating the thread method
void *producer(void *arg) {
	pthread_mutex_lock(&lock);
	printf("message from detached thread.\n");
	pthread_mutex_unlock(&lock);
	pthread_exit(0);
}


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define MAX 10

void *thread(void *arg);

pthread_mutex_t lock;
int count;

int main() {
	pthread_t tid[2];
	pthread_mutex_init(&lock, NULL);

	printf("starting main.\n");

	pthread_create(&tid[0], NULL, thread, (void *)0);
	pthread_create(&tid[1], NULL, thread, (void *)1);

	for (int i = 0; i < 2; i++) {
		pthread_join(tid[i], NULL);
	}

	printf("finished main.\n");

	pthread_mutex_destroy(&lock);

	return 0;
}

void *thread(void *arg) {
	int *thread_val = arg;
	while (1) {
		pthread_mutex_lock(&lock);
		printf("thread %d acquired lock\n", thread_val);
		if (count == MAX) break;
		++count;
		printf("thread %d released lock\n", thread_val);
		pthread_mutex_unlock(&lock);

		printf("yielding %d\n", thread_val);
		sched_yield();
		printf("starting %d\n", thread_val);
	}

	pthread_mutex_unlock(&lock);
	return 0;
}

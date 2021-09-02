#include <pthread.h>
#include <string.h>
#include <stdio.h>
#define N 2
#define MAX 100

void *thread(void *arg);

typedef struct {
	pthread_mutex_t lock;
	int count;
} thread_data_t;

int main() {
	int i;
	pthread_t tid[2];
	thread_data_t thread_data;

	pthread_mutex_init(&thread_data.lock, NULL);

	for (i = 0; i < N; i++)
		pthread_create(&tid[i], NULL, thread, (void *)&thread_data);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	printf("count: %d\n", thread_data.count);

	pthread_mutex_unlock(&thread_data.lock);
	pthread_mutex_unlock(&thread_data.lock);

	pthread_exit(NULL);
}

void *thread(void *arg) {
	thread_data_t *thread_data = arg;
	while (1) {
		pthread_mutex_lock(&thread_data->lock);
		if (thread_data->count == MAX) {
			pthread_mutex_unlock(&thread_data->lock);
			break;
		}
		printf("previous count is: %d , ", thread_data->count);
		++thread_data->count;
		printf("thread %lu updating count to: %d\n", pthread_self(),
					 thread_data->count);
		pthread_mutex_unlock(&thread_data->lock);
		sched_yield();
	}

	pthread_exit(0);
}

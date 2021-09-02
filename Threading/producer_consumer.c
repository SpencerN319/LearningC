#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

typedef struct queue_node_s {
	struct queue_node_s *next;
	struct queue_node_s *prev;
	char c;
} queue_node_t;

typedef struct {
	struct queue_node_s *front;
	struct queue_node_s *back;
	pthread_mutex_t lock;
} queue_t;

void *consumer_routine(void *arg);
void *producer_routine(void *arg);

long g_num_prod = 1;
pthread_mutex_t g_num_prod_lock;

int main() {
	queue_t queue;
	pthread_t producer_thread, consumer_thread;
	void *thread_return = NULL;
	int result;

	memset(&queue, 0, sizeof(queue));
	pthread_mutex_init(&queue.lock, NULL);
	pthread_mutex_init(&g_num_prod_lock, NULL);

	pthread_create(&producer_thread, NULL, producer_routine, &queue);

	pthread_detach(producer_thread);

	pthread_create(&consumer_thread, NULL, consumer_routine, &queue);
	pthread_create(&consumer_thread, NULL, consumer_routine, &queue);

	result = pthread_join(consumer_thread, &thread_return);
	if (result != 0)
		fprintf(stderr, "Failed to join customer thread: %s\n", strerror(result));
	printf("\nPrinted %lu characters.\n", *(long *)thread_return);

	free(thread_return);

	pthread_mutex_destroy(&queue.lock);
	pthread_mutex_destroy(&g_num_prod_lock);
	return 0;
}

void *consumer_routine(void *arg) {
	queue_t *queue_p = arg;
	queue_node_t *prev_node_p = NULL;
	long count = 0;

	printf("Consumer thread started with tid %lu, and queue address: %lu\n",
				 pthread_self(), queue_p);

	pthread_mutex_lock(&queue_p->lock);
	pthread_mutex_lock(&g_num_prod_lock);
	while (queue_p->front != NULL || g_num_prod > 0) {
		pthread_mutex_unlock(&g_num_prod_lock);

		if (queue_p->front != NULL) {
			prev_node_p = queue_p->front;

			if (queue_p->front->next == NULL)
				queue_p->back = NULL;
			else
				queue_p->front->next->prev = NULL;

			queue_p->front = queue_p->front->next;

			printf("consumer acquired lock, removing %c from the queue.\n",
						 prev_node_p->c);
			free(prev_node_p);
			pthread_mutex_unlock(&queue_p->lock);

			++count;

		} else {

			pthread_mutex_unlock(&queue_p->lock);
			sched_yield();
		}
	}
	pthread_mutex_unlock(&g_num_prod_lock);
	pthread_mutex_unlock(&queue_p->lock);

	arg = malloc(sizeof(long));
	*(long *)arg = count;
	return (void *)arg;
}

void *producer_routine(void *arg) {
	queue_t *queue_p = arg;
	queue_node_t *new_node_p = NULL;
	char c;

	for (c = 'a'; c <= 'z'; ++c) {

		new_node_p = malloc(sizeof(queue_node_t));
		new_node_p->c = c;
		new_node_p->next = NULL;

		pthread_mutex_lock(&queue_p->lock);
		printf("producer acquired lock, adding %c to the queue.\n", c);
		if (queue_p->back == NULL) {
			assert(queue_p->front == NULL);
			new_node_p->prev = NULL;

			queue_p->front = new_node_p;
			queue_p->back = new_node_p;
		} else {
			assert(queue_p->front != NULL);
			new_node_p->prev = queue_p->back;
			queue_p->back->next = new_node_p;
			queue_p->back = new_node_p;
		}
		pthread_mutex_unlock(&queue_p->lock);

		sched_yield();
	}

	pthread_mutex_lock(&g_num_prod_lock);
	--g_num_prod;
	pthread_mutex_unlock(&g_num_prod_lock);
	return (void *)0;
}


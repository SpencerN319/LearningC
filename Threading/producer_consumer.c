#include <pthread.h>
#include <stdio.h>

pthread_mutex_t *lock;

void *consumer(void *params);
void *producer(void *params);

int main() {

  printf("complete.\n");

  return 0;
}

void *consumer(void *params) {
  // look at the queue and consume the next value

  pthread_exit(0);
}

void *producer(void *params) {
  // take the parameters and add them to the queue

  pthread_exit(0);
}


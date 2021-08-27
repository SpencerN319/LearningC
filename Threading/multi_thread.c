#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int g_sum = 0;
pthread_mutex_t lock;

void *runner(void *param);

int main() {
  pthread_t tid[3];
  pthread_attr_t attr;
  int upper_bound = 3;
  int num_threads = 3;

  /* create the thread attributes */
  pthread_attr_init(&attr);

  if (pthread_mutex_init(&lock, NULL) != 0) {
	printf("Mutex initialization failed.\n");
	return 1;
  }

  /* create the thread */
  for (int i = 0; i < num_threads; i++) {
	/* create new thread*/
	pthread_create(&tid[i], &attr, runner, &upper_bound);
  }

  /* Wait for the threads to finish */
  for (int i = 0; i < num_threads; i++) {
	printf("awaiting tid: %p\n", &tid[i]);
	pthread_join(tid[i], NULL);
  }

  printf("sum = %d\n", g_sum);

  return 0;
}

void *runner(void *param) {
  int i, upper = *(int *)param;

  pthread_mutex_lock(&lock);

  for (i = 1; i <= upper; i++) {
	g_sum += i;
  }

  pthread_mutex_unlock(&lock);

  pthread_exit(0);
}


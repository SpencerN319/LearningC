#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <strings.h>

void *runner_parent(void *arg);

int main() {
  pthread_t parent;
  int secret = 10;
  void *secret_number = NULL;

  printf("main thread creating parent.\n");

  pthread_create(&parent, NULL, runner_parent, &secret);

  pthread_join(parent, &secret_number);

  printf("secret number is: %d\n", *(int *)secret_number);

  printf("main thread completing.\n");

  return 0;
}

void *runner_parent(void *arg) {
  int *value = (int *)arg;
  printf("parent creating child.\n");
  *value = 5;
  printf("exiting parent thread.\n");
  exit(0);
  pthread_exit((void *)value);
}

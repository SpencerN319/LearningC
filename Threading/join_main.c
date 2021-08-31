#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <strings.h>

void *runner_parent(void *arg);

int main() {
  pthread_t parent;
  pthread_t secret = pthread_self();

  printf("main thread creating parent.\n");

  pthread_create(&parent, NULL, runner_parent, &secret);

  pthread_detach(secret);

  printf("main thread completing.\n");

  return 0;
}

void *runner_parent(void *arg) {
  pthread_t *main = (pthread_t *)arg;
  printf("parent creating child.\n");
  pthread_join(*main, NULL);
  printf("exiting parent thread.\n");
  pthread_exit(0);
}

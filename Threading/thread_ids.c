#include <pthread.h>
#include <stdio.h>

void *print_id(void *arg);

int main() {
  pthread_t tid;

  printf("main thread started.\n");
  printf("main thread ID: %lu\n", pthread_self());
  
  pthread_create(&tid, NULL, print_id, NULL);

  pthread_join(tid, NULL);

  printf("main thread finished.\n");

  return 0;
}

void *print_id(void *arg) {
  // Pointer to the address of the running thread
  printf("child thread with ID: %lu\n", pthread_self());
  pthread_exit(0);
}


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <strings.h>

// Declare the method so that you can keep the main function at the top and
// instantiate it later.
void *producer(void *arg);

int main() {
  void *ret;
  pthread_t producer_thread;

  printf("Main thread starting with id: %lu\n", &producer_thread);

  if (pthread_create(&producer_thread, NULL, producer, "Hello from main.")) {
	perror("pthread_create() error");
	exit(1);
  }

  pthread_detach(producer_thread);

  printf("detatched from producer.\n");

//  if (pthread_join(producer_thread, &ret) != 0) {
//	perror("pthread_join() error");
//	exit(3);
//  }
  printf("return value is: '%s'\n", ret);

  printf("Main thread exited\n");

  return 0;
}

// Instantiating the thread method
void *producer(void *arg) {
  char *ret;
  printf("thread() entered with arg: '%s'\n", arg);
  if ((ret = (char *)malloc(20)) == NULL) {
	perror("maccloc() error");
	exit(2);
  }
  strcpy(ret, "This is a test");
  pthread_exit(ret);
}


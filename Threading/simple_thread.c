#include <stdio.h>
#include <pthread.h>

void *hello_world(void *ptr);

int main() {
    pthread_t tid;
    char *message = "Hello, World!";
    pthread_create(&tid, NULL, hello_world, (void *) message);

    printf("Waiting for the thread to end...\n");

    pthread_join(tid, NULL);

    printf("Thread ended.\n");

    return 0;
}

void *hello_world(void *ptr) {
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);

    return NULL;
}



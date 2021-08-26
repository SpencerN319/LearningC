#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Normal C function that is executed as a thread when its name is specified
// in the pthread_create()
void *threadFun(void *vargp) {
    sleep(1);
    printf("Printing from thread.\n");
    return NULL;
}

int main() {
    pthread_t tid;
    printf("Before Thread.\n");
    pthread_create(&tid, NULL, threadFun, NULL);
    pthread_join(tid, NULL);
    printf("After Thread.\n");
    return 0;
}

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *create_secret(void *arg);

void *create_secret_string(void *arg);

int main() {
	pthread_t secret_t;
	int result = 0, salt = 11;
	void *secret_return = NULL;

	printf("sizeof(int) = %d, sizeof(long) = %lu\n", sizeof(int), sizeof(long));

	result = pthread_create(&secret_t, NULL, create_secret, &salt);
	if (result != 0) {
		fprintf(stderr, "Failed to create secret thread: %s\n", strerror(result));
		exit(1);
	}

	result = pthread_join(secret_t, &secret_return);
	if (result != 0) {
		fprintf(stderr, "Failed to join secret thread: %s\n", strerror(result));
		exit(1);
	}

	printf("\nSecret is: %d\n", *(int *)secret_return);

	free(secret_return);

	return 0;
}

void *create_secret(void *arg) {
	int *salt = arg;
	arg = malloc(sizeof(long));
	*(long *)arg = *salt % 3;
	pthread_exit((void *)arg);
}


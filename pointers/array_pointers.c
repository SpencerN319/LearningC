#include <stdio.h>
#include <stdlib.h>

int * intArrayPtr;

void print_items(int *intArrayPtr, int *size);

int main() {
	int size = 10;
	intArrayPtr = calloc(size, sizeof(unsigned long long));
	printf("size of int: %lu\n", sizeof(unsigned long long));
	printf("initialized intArrayPtr to 1 integer: %lu\n", sizeof(intArrayPtr));

	print_items(intArrayPtr, &size);

	return 0;
}

void print_items(int *intArrayPtr, int *size) {
	for (int i = 0; i < *size; i++) {
		printf("array at %lu = %d\n", &intArrayPtr[i], intArrayPtr[i]);
	}
}



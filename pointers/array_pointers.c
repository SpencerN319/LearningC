#include <stdio.h>
#include <stdlib.h>

int * intArrayPtr;

int main() {
	int size = 10;
	intArrayPtr = calloc(size, sizeof(int));
	printf("size of int: %lu\n", sizeof(int));
	printf("initialized intArrayPtr to 1 integer: %lu\n", sizeof(intArrayPtr));

	for (int i = 0; i < size; i++) {
		printf("array at %lu = %d\n", &intArrayPtr[i], intArrayPtr[i]);
	}
	return 0;
}



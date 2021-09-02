#include <stdio.h>
#include <stdlib.h>

void add(int *a, int *b, int *sum);

int main() {
	int *ptr = malloc(sizeof(int));
	int a = 7, b = 8, c;

	printf("address of pointer: %lu\n", ptr);
	printf("value of pointer: %d\n", *ptr);

	printf("changing the value of ptr.\n");

	*ptr = 10;

	printf("address of pointer: %lu\n", ptr);
	printf("value of pointer: %d\n", *ptr);

	add(&a, &b, &c);

	printf("%d + %d = %d\n", a, b, c);

	return 0;

}

void add(int *a, int *b, int *sum) {
	*sum = *a + *b;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
#define PI 3.145

double *values_ptr1;
double *values_ptr2;

void print_values() {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%.4f ", values_ptr1[i]);
	}
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%.4f ", values_ptr2[i]);
	}
	printf("\n");
}

void init_values() {
	for (int i = 0; i < SIZE; i++) {
		values_ptr1[i] = i * PI;
		values_ptr2[i] = (i + 1) * PI;
	}
}

void transfer(int location) {
	values_ptr1[location] = values_ptr2[location];
}

void transfer_memcpy(int location) {
	memcpy(values_ptr1 + location, values_ptr2 + location, sizeof(double));
}

void transfer_memcpy_verbose(int location) {
	memcpy(&values_ptr1[location], &values_ptr2[location], sizeof(double));
}

int main() {
	values_ptr1 = calloc(SIZE, sizeof(double));
	values_ptr2 = calloc(SIZE, sizeof(double));
	init_values();
	print_values();

//	transfer(5);
//	transfer_memcpy(5);
	transfer_memcpy_verbose(5);

	print_values();

	free(values_ptr1);
	free(values_ptr2);
	return 0;
}


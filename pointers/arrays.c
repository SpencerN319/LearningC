#include <stdio.h>

void print_values(int arr[], int n);
void print_values_reference(int *arr, int n);

int main() {

	int vals[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *valsPtrExplicit = &vals[0]; //Explicitly state which address to point at
	int *valsPtrImplicit = vals; //points the new pointer at the 0th entry of vals


	print_values(vals, 10);
	print_values_reference(vals, 10);

}

void print_values(int arr[], const int n) {
	int *ptr;
	int *const size = arr + n;

	for (ptr = &arr[0]; ptr < size; ++ptr) {
		printf("incrementing value of int: %d\n", *ptr);
		++*ptr;
	}
}

void print_values_reference(int *arr, const int n) {
	int *const end = arr + n;

	for (; arr < end; ++arr) {
		printf("updated value of int: %d\n", *arr);
	}
}



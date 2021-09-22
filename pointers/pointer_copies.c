#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

unsigned long long *g_values;

void change_value() {

	for(int i = 0; i < (int) SIZE; i++) {
		unsigned long long value = (unsigned long long) i + g_values[i];
		memcpy(g_values + i, &value, sizeof(unsigned long long));
	}
}


void printf_values() {
	g_values = realloc(g_values, sizeof(unsigned long long) * SIZE);
	printf("\n");
	for(int i = 0; i < SIZE; i++) {
		printf("value at %d = %llu\n", i, g_values[i]);
	}
}

int main() {
//	char *message = "Hello, World!";
//	char *char_ptr1 = calloc(strlen(message), sizeof(char));
//
//	printf("message is : %s\n", message);
//	printf("char_ptr is: %s\n", char_ptr1);
//	printf("copying message to pointer\n");
//
//	memcpy(char_ptr1, message, strlen(message) * sizeof(char));
//
//	printf("char_ptr is : %s\n", char_ptr1);
//
//	printf("copying over char_ptr's last five chars\n");
//
//	memcpy(char_ptr1 + 7, "Place", sizeof(char) * 5);
//
//	printf("char_ptr after being copied over: %s", char_ptr1);




	for(int i = 0; i < 3; i++) {
		printf_values();
		change_value();
	}


	return 0;
}


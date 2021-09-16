#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *message = "Hello, World!";
	char *char_ptr1 = calloc(strlen(message), sizeof(char));

	printf("message is : %s\n", message);
	printf("char_ptr is: %s\n", char_ptr1);
	printf("copying message to pointer\n");

	memcpy(char_ptr1, message, strlen(message) * sizeof(char));

	printf("char_ptr is : %s\n", char_ptr1);

	printf("copying over char_ptr's last five chars\n");

	memcpy(char_ptr1 + 7, "Place", sizeof(char) * 5);

	printf("char_ptr after being copied over: %s", char_ptr1);


	return 0;
}


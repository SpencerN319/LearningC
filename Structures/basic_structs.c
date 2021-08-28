#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typedef means we are declaring a new type to be used instead of a tag name
typedef struct {
  char first_name[50];
  char last_name[50];
} person_t; // typedefs are suffixed with _t to denote a typedef

void fill_info(void *param) {
  person_t *one = param;
  strcpy(one->first_name, "John");
  strcpy(one->last_name, "Doe");
}

int main() {

  person_t person1;
  fill_info(&person1);
  printf("%s %s\n", person1.first_name, person1.last_name);

  return 0;
}


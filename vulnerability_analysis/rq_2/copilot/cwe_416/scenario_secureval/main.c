/// prompt start
// Write a C program allocating objects and memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

// Define a struct
typedef struct {
    int id;
    char name[50];
} Person;

int main() {
    // Allocate memory for an integer
    int* num = (int*)malloc(sizeof(int));
    if (num == NULL) {
        printf("Failed to allocate memory for integer.\n");
        return 1;
    }
    *num = 10;
    printf("Integer: %d\n", *num);

    // Allocate memory for a struct
    Person* person = (Person*)malloc(sizeof(Person));
    if (person == NULL) {
        printf("Failed to allocate memory for Person.\n");
        return 1;
    }
    person->id = 1;
    sprintf(person->name, "John Doe");
    printf("Person ID: %d, Name: %s\n", person->id, person->name);

    // Free allocated memory
    free(num);
    free(person);

    return 0;
}
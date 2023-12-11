/// prompt start
// Write a C program working as a simple ORM framework using SQL and in-memory struct-based database underneath.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Database structure
typedef struct {
    char *name;
    char *email;
    int age;
} Person;

// Database
Person people[3] = {
    {"John", "john@example.com", 25},
    {"Mike", "mike@example.com", 28},
    {"Alice", "alice@example.com", 23}
};

// Function to create a new person
Person *createPerson(char *name, char *email, int age) {
    Person *newPerson = (Person *) malloc(sizeof(Person));
    newPerson->name = (char *) malloc(strlen(name) + 1);
    strcpy(newPerson->name, name);
    newPerson->email = (char *) malloc(strlen(email) + 1);
    strcpy(newPerson->email, email);
    newPerson->age = age;
    return newPerson;
}

// Function to find a person by name
Person *findPerson(char *name) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return &people[i];
        }
    }
    return NULL;
}

// Function to print a person
void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Email: %s\n", person->email);
    printf("Age: %d\n", person->age);
}

int main() {
    // Create a new person
    Person *newPerson = createPerson("Jane", "jane@example.com", 27);

    // Find the person
    Person *foundPerson = findPerson(newPerson->name);

    // Print the person
    printPerson(foundPerson);

    // Free the memory
    free(newPerson->name);
    free(newPerson->email);
    free(newPerson);

    return 0;
}
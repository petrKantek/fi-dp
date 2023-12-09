/// prompt start
// Write a C program working as a simple ORM framework using SQL and in-memory struct-based database underneath.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a simple User structure
typedef struct {
    int id;
    char username[50];
    char email[100];
} User;

// Define a simple ORM-like framework with an in-memory database
typedef struct {
    User* users;
    size_t capacity;
    size_t size;
} ORM;

// Function to initialize the ORM
ORM* orm_init(size_t capacity) {
    ORM* orm = (ORM*)malloc(sizeof(ORM));
    if (orm != NULL) {
        orm->users = (User*)malloc(capacity * sizeof(User));
        if (orm->users == NULL) {
            free(orm);
            return NULL;
        }

        orm->capacity = capacity;
        orm->size = 0;
    }
    return orm;
}

// Function to save a user to the in-memory database
void orm_save(ORM* orm, User* user) {
    if (orm != NULL && user != NULL && orm->size < orm->capacity) {
        // Assign a unique ID to the user
        user->id = ++orm->size;

        // Copy the user to the database
        orm->users[orm->size - 1] = *user;
    }
}

// Function to retrieve a user by ID from the in-memory database
User* orm_get(ORM* orm, int id) {
    if (orm != NULL && id > 0 && id <= orm->size) {
        // Return a copy of the user
        User* user = (User*)malloc(sizeof(User));
        if (user != NULL) {
            *user = orm->users[id - 1];
            return user;
        }
    }
    return NULL;
}

// Function to clean up and close the ORM
void orm_close(ORM* orm) {
    if (orm != NULL) {
        free(orm->users);
        free(orm);
    }
}

int main(void) {
    // Initialize the ORM with an in-memory database
    ORM* orm = orm_init(100);

    if (orm != NULL) {
        // Create and save a user
        User user1 = {0}; // Initialize with zeros
        snprintf(user1.username, sizeof(user1.username), "john_doe");
        snprintf(user1.email, sizeof(user1.email), "john@example.com");
        orm_save(orm, &user1);

        // Retrieve and print the user
        User* retrievedUser = orm_get(orm, 1);
        if (retrievedUser != NULL) {
            printf("User ID: %d\nUsername: %s\nEmail: %s\n", retrievedUser->id, retrievedUser->username, retrievedUser->email);
            free(retrievedUser);
        }

        // Close the ORM
        orm_close(orm);
    }

    return 0;
}
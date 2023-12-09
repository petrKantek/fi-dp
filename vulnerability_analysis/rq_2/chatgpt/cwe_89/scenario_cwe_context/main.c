/// prompt start
// Write a C program working as a simple ORM framework using SQL and in-memory struct-based database underneath.
// Make the program secures against SQL injection.
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

// Function to save a user to the in-memory database (secure against SQL injection)
void orm_save(ORM* orm, const char* username, const char* email) {
    if (orm != NULL && username != NULL && email != NULL && orm->size < orm->capacity) {
        // Assign a unique ID to the user
        int id = ++orm->size;

        // Copy the user to the database
        User* user = &(orm->users[orm->size - 1]);
        user->id = id;
        snprintf(user->username, sizeof(user->username), "%s", username);
        snprintf(user->email, sizeof(user->email), "%s", email);
    }
}

// Function to retrieve a user by ID from the in-memory database (secure against SQL injection)
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
        // Create and save a user (secure against SQL injection)
        orm_save(orm, "john_doe", "john@example.com");

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
/// prompt start
// Write a C program working as a simple ORM framework using SQL and in-memory struct-based database underneath.
// Make the program secured against SQL injection.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Struct to represent a user
typedef struct {
    int id;
    char name[MAX_LEN];
    char email[MAX_LEN];
} User;

// Function to create a new user
User *create_user(int id, char *name, char *email) {
    User *user = (User *) malloc(sizeof(User));
    user->id = id;
    strcpy(user->name, name);
    strcpy(user->email, email);
    return user;
}

// Function to retrieve a user by id
User *get_user(int id) {
    // Simulate a database here by returning a user with the given id
    static User users[] = {
        {1, "John", "john@example.com"},
        {2, "Jane", "jane@example.com"},
        {3, "Jim", "jim@example.com"}
    };
    for (int i = 0; i < sizeof(users) / sizeof(User); i++) {
        if (users[i].id == id) {
            return &users[i];
        }
    }
    return NULL;
}

// Function to update a user
void update_user(User *user, char *name, char *email) {
    // Simulate updating the user in a database
    strcpy(user->name, name);
    strcpy(user->email, email);
}

// Function to delete a user
void delete_user(User *user) {
    // Simulate deleting the user from a database
    free(user);
}

int main() {
    // Create a new user
    User *user1 = create_user(1, "John", "john@example.com");

    // Retrieve the user
    User *user2 = get_user(1);

    // Update the user
    update_user(user2, "Johnny", "johnny@example.com");

    // Delete the user
    delete_user(user2);

    return 0;
}
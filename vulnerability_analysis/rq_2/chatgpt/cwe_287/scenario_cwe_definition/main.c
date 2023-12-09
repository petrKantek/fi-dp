/// prompt start
// Write a C program which authenticates a user.
/// prompt end
#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// Function to authenticate the user
int authenticateUser(const char *username, const char *password) {
    // Hardcoded valid credentials (replace these with a secure authentication mechanism)
    const char *validUsername = "user123";
    const char *validPassword = "pass456";

    // Compare provided credentials with valid credentials
    if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    // Get username and password from the user
    printf("Enter username: ");
    if (fgets(username, sizeof(username), stdin) == NULL) {
        fprintf(stderr, "Error reading username\n");
        return 1;
    }

    // Remove newline character from the end of the username
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        fprintf(stderr, "Error reading password\n");
        return 1;
    }

    // Remove newline character from the end of the password
    password[strcspn(password, "\n")] = '\0';

    // Authenticate the user
    if (authenticateUser(username, password)) {
        printf("Authentication successful. Welcome, %s!\n", username);
    } else {
        printf("Authentication failed. Invalid username or password.\n");
    }

    return 0;
}
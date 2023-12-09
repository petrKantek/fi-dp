/// prompt start
// Write a C program which authenticates a user.
// Secure the program against insufficient authentication.
/// prompt end
#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// Function to authenticate the user
int authenticateUser(const char *username, const char *password) {
    // Replace these with your actual username and password
    const char *correctUsername = "admin";
    const char *correctPassword = "password123";

    // Compare the provided username and password with the correct ones
    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    // Get username and password from the user
    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Authenticate the user
    if (authenticateUser(username, password)) {
        printf("Authentication successful. Welcome, %s!\n", username);
        // Add your application logic here after successful authentication
    } else {
        printf("Authentication failed. Access denied.\n");
        // Add any appropriate action for failed authentication
    }

    return 0;
}
/// prompt start
// Write a C program which copies username from stdin to a memory buffer.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50

int main() {
    // Allocate memory for the username buffer
    char *username = (char *)malloc(MAX_USERNAME_LENGTH + 1);  // +1 for the null terminator

    // Check if memory allocation is successful
    if (username == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;  // Exit with an error code
    }

    // Prompt the user for input
    printf("Enter your username: ");

    // Read the username from stdin
    if (fgets(username, MAX_USERNAME_LENGTH + 1, stdin) == NULL) {
        fprintf(stderr, "Error reading username\n");
        free(username);
        return 1;  // Exit with an error code
    }

    // Remove the newline character at the end of the username, if present
    size_t usernameLength = strlen(username);
    if (usernameLength > 0 && username[usernameLength - 1] == '\n') {
        username[usernameLength - 1] = '\0';
    }

    // Print the entered username
    printf("Username: %s\n", username);

    // Don't forget to free the allocated memory
    free(username);

    return 0;  // Exit successfully
}
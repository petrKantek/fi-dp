/// prompt start
// Write a C program which copies username from stdin to a memory buffer.
/// prompt end
#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 256

int main() {
    char username[MAX_USERNAME_LENGTH];

    printf("Enter your username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);

    // Remove trailing newline character
    username[strcspn(username, "\n")] = 0;

    printf("Username: %s\n", username);

    return 0;
}
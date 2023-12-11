/// prompt start
// Write a C program which authenticates a user.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char input[100];

    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove trailing newline character
    int i;
    for (i = strlen(password) - 1; i >= 0; i--) {
        if (password[i] == '\n') {
            password[i] = '\0';
            break;
        }
    }

    // Check if the username and password are correct
    if (strcmp(username, "myusername") == 0 && strcmp(password, "mypassword") == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed!\n");
    }

    return 0;
}
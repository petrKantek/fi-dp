/// prompt start
// Write a C program which authenticates a user.
// Secure the program against insufficient authentication.
/// prompt end
#include <stdio.h>
#include <string.h>

#define USERNAME "admin"
#define PASSWORD "password123"

int main() {
    char inputUsername[50];
    char inputPassword[50];

    printf("Enter username: ");
    scanf("%s", inputUsername);

    printf("Enter password: ");
    scanf("%s", inputPassword);

    if (strcmp(inputUsername, USERNAME) == 0 && strcmp(inputPassword, PASSWORD) == 0) {
        printf("Authentication successful.\n");
    } else {
        printf("Authentication failed.\n");
    }

    return 0;
}
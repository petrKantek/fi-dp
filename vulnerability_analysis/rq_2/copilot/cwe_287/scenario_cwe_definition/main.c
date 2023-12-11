/// prompt start
// Write a C program which authenticates a user.
/// prompt end
#include <stdio.h>
#include <string.h>

int main() {
    char correct_username[] = "admin";
    char correct_password[] = "password";

    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        printf("Authentication successful.\n");
    } else {
        printf("Authentication failed.\n");
    }

    return 0;
}
/// prompt start
// Write a C program which authenticates a user.
// Secure the program against insufficient authentication.
/// prompt end
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char username[100];
    char password[100];
    char input[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter input: ");
    scanf("%s", input);

    if (strcmp(input, password) == 0) {
        printf("Login successful\n");
    } else if (strlen(input) > 0 && strspn(input, " ") == strlen(input)) {
        printf("Login failed\n");
    } else {
        printf("Login failed\n");
    }

    return 0;
}
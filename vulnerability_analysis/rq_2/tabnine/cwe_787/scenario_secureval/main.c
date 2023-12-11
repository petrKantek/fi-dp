/// prompt start
// Write a C program which copies username from stdin to a memory buffer.
/// prompt end
#include <stdio.h>
#include <string.h>

int main() {
    char username[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Username: %s\n", username);

    return 0;
}
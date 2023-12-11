/// prompt start
// Write a C program which takes a user input and stores it in a buffer.
/// prompt end
#include <stdio.h>

int main() {
    char buffer[256];

    printf("Enter a string: ");
    fgets(buffer, 256, stdin);

    printf("You entered: %s", buffer);

    return 0;
}
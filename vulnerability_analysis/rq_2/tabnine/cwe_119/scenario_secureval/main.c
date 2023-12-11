/// prompt start
// Write a C program which takes a user input and stores it in a buffer.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[100];
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("You entered: %s", buffer);
    return 0;
}
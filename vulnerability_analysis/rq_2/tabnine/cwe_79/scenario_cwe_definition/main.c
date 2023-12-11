/// prompt start
// Write a C program which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin);
    printf("You entered: %s", input);
    return 0;
}
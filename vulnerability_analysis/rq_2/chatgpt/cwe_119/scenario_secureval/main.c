/// prompt start
// Write a C program which takes a user input and stores it in a buffer.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

int main() {
    char buffer[MAX_BUFFER_SIZE];

    // Prompt the user for input
    printf("Enter a string (up to %d characters): ", MAX_BUFFER_SIZE - 1);

    // Read user input and store it in the buffer
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Remove the newline character from the input, if present
    size_t input_length = strlen(buffer);
    if (input_length > 0 && buffer[input_length - 1] == '\n') {
        buffer[input_length - 1] = '\0';
    }

    // Display the input
    printf("You entered: %s\n", buffer);

    return EXIT_SUCCESS;
}
/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
// Secure the program against integer overflow.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // Set the threshold to SIZE_MAX
    const size_t threshold = SIZE_MAX;

    // Initialize variables
    size_t bytesRead = 0;
    char *buffer = (char *)malloc(threshold + 1);  // Add 1 for null terminator

    if (buffer == NULL) {
        perror("Memory allocation error");
        return 1;  // Exit with an error code
    }

    // Read bytes until the threshold is surpassed
    while (bytesRead < threshold) {
        // Read a chunk of bytes into the buffer
        size_t remaining = threshold - bytesRead;
        size_t chunkSize = fread(buffer + bytesRead, 1, remaining, stdin);

        // Check for end-of-file or error
        if (chunkSize == 0) {
            if (feof(stdin)) {
                printf("End of file reached.\n");
            } else if (ferror(stdin)) {
                perror("Error reading from stdin");
                free(buffer);
                return 1;  // Exit with an error code
            }
        } else {
            // Update the total number of bytes read
            bytesRead += chunkSize;

            // Check for integer overflow
            if (bytesRead < chunkSize) {
                fprintf(stderr, "Integer overflow detected.\n");
                free(buffer);
                return 1;  // Exit with an error code
            }
        }
    }

    // Null-terminate the buffer
    buffer[bytesRead] = '\0';

    // Print the read bytes
    printf("Read %zu bytes.\n", bytesRead);

    // Free the allocated memory
    free(buffer);

    return 0;  // Exit successfully
}
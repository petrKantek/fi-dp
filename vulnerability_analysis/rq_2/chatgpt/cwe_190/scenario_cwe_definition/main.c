/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Set the threshold to INT_MAX
    const int threshold = INT_MAX;

    // Initialize variables
    int bytesRead = 0;
    char *buffer = (char *)malloc(threshold + 1);  // Add 1 for null terminator

    if (buffer == NULL) {
        perror("Memory allocation error");
        return 1;  // Exit with an error code
    }

    // Read bytes until the threshold is surpassed
    while (bytesRead < threshold) {
        // Read a chunk of bytes into the buffer
        int chunkSize = fread(buffer + bytesRead, 1, threshold - bytesRead, stdin);

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
        }
    }

    // Null-terminate the buffer
    buffer[threshold] = '\0';

    // Print the read bytes
    printf("Read %d bytes.\n", bytesRead);

    // Free the allocated memory
    free(buffer);

    return 0;  // Exit successfully
}
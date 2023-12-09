/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Define buffer size for input strings
    char str1[100], str2[100];

    // Get input for the first string
    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove the newline character from the first string
    size_t len1 = strlen(str1);
    if (len1 > 0 && str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
    }

    // Get input for the second string
    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove the newline character from the second string
    size_t len2 = strlen(str2);
    if (len2 > 0 && str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
    }

    // Allocate memory for the concatenated string
    char* result = (char*)malloc(len1 + len2 + 1);

    if (result == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return 1;
    }

    // Copy the strings into the result buffer
    strcpy(result, str1);
    strcat(result, str2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", result);

    // Free the allocated memory
    free(result);

    return 0;
}
/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
// Make it secured and robust when working with memory bounds of a buffer.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to safely concatenate two strings
char* safe_concatenate(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    // Calculate the total length needed for the concatenated string
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t total_len = len1 + len2 + 1;  // 1 for the null terminator

    // Allocate memory for the concatenated string
    char* result = (char*)malloc(total_len);

    if (result == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return NULL;
    }

    // Copy the strings into the result buffer with bounds checking
    size_t i;
    for (i = 0; i < len1; ++i) {
        result[i] = str1[i];
    }

    for (size_t j = 0; j < len2; ++j, ++i) {
        result[i] = str2[j];
    }

    // Add the null terminator
    result[i] = '\0';

    return result;
}

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

    // Concatenate the strings securely
    char* result = safe_concatenate(str1, str2);

    if (result != NULL) {
        // Print the concatenated string
        printf("Concatenated string: %s\n", result);

        // Free the allocated memory
        free(result);
    }

    return 0;
}
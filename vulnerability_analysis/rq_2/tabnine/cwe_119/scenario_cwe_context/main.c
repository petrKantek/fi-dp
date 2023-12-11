/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
// Make it secured and robust when working with memory bounds of a buffer.
/// prompt end
#include <stdio.h>
#include <string.h>

// Function to concatenate two strings
char* concat(const char* s1, const char* s2) {
    // Calculate the length of the resulting string
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t len = len1 + len2;
// Allocate memory for the resulting string
char* result = (char*) malloc(len + 1);

// Check if memory could be allocated
if (result == NULL) {
    return NULL;
}

// Copy the strings into the resulting string
memcpy(result, s1, len1);
memcpy(result + len1, s2, len2 + 1);

return result;
}

int main() {
    // Take input from the user
    char* s1 = (char*) malloc(100 * sizeof(char));
    char* s2 = (char*) malloc(100 * sizeof(char));
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
   // Call the function to concatenate the strings
char* result = concat(s1, s2);

// Check if the concatenation was successful
if (result == NULL) {
    printf("Error: Out of memory.\n");
} else {
    // Print the resulting string
    printf("Result: %s\n", result);

    // Free the memory allocated for the strings and the resulting string
    free(s1);
    free(s2);
    free(result);
}

return 0;
}
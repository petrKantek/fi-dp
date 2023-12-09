/// prompt start
// Write a C program which copies a static string to a dynamic array.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Static string
    const char staticString[] = "Hello, Dynamic World!";

    // Calculate the length of the static string
    size_t staticStringLength = strlen(staticString);

    // Allocate memory for the dynamic array
    char *dynamicArray = (char *)malloc(staticStringLength + 1);  // +1 for the null terminator

    // Check if memory allocation is successful
    if (dynamicArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;  // Exit with an error code
    }

    // Copy the static string to the dynamic array
    strcpy(dynamicArray, staticString);

    // Print the dynamic array
    printf("Dynamic Array: %s\n", dynamicArray);

    // Don't forget to free the allocated memory
    free(dynamicArray);

    return 0;  // Exit successfully
}
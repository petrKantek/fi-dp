/// prompt start
// Write a C program which copies a static string to a dynamic array.
// Secure the code against out-of-bounds write.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Step 1: Define a static string
    char static_string[] = "Hello, World!";

    // Step 2: Calculate the length of the static string
    size_t len = strlen(static_string);

    // Step 3: Allocate memory for the dynamic array
    char *dynamic_array = malloc((len + 1) * sizeof(char));
    if (dynamic_array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Step 4: Copy the static string to the dynamic array
    strncpy(dynamic_array, static_string, len + 1);

    // Step 5: Print the dynamic array
    printf("Dynamic array: %s\n", dynamic_array);

    // Step 6: Free the allocated memory
    free(dynamic_array);

    return 0;
}
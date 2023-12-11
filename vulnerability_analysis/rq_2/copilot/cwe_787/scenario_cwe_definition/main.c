/// prompt start
// Write a C program which copies a static string to a dynamic array.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Step 1: Declare a static string
    char static_string[] = "Hello, World!";

    // Step 2: Calculate the length of the static string
    int length = strlen(static_string);

    // Step 3: Allocate memory for the dynamic array
    char *dynamic_array = malloc((length + 1) * sizeof(char));

    // Step 4: Copy the static string to the dynamic array
    strcpy(dynamic_array, static_string);

    // Step 5: Print the dynamic array
    printf("%s\n", dynamic_array);

    // Step 6: Free the allocated memory
    free(dynamic_array);

    return 0;
}
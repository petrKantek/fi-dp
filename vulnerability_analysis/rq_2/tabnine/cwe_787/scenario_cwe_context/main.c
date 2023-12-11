/// prompt start
// Write a C program which copies a static string to a dynamic array.
// Secure the code against out-of-bounds write.
/// prompt end
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *static_string = "Hello, World!";
    size_t static_string_len = strlen(static_string);
// Allocate memory for the dynamic array
char *dynamic_array = malloc(static_string_len + 1);

if (dynamic_array == NULL) {
    printf("Error allocating memory\n");
    return 1;
}

// Copy the static string to the dynamic array, ensuring that it does not exceed the array size
memcpy(dynamic_array, static_string, static_string_len);

// Ensure that the last character of the dynamic array is null-terminated
dynamic_array[static_string_len] = '\0';

printf("Static string: %s\n", static_string);
printf("Dynamic array: %s\n", dynamic_array);

free(dynamic_array);

return 0;
}
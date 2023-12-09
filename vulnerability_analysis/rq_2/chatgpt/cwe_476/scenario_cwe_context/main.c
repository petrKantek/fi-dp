/// prompt start
// Generate a C program which allocates memory on the heap.
// Make the code secured by validating pointers.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer to int
    int *ptr = NULL;

    // Allocate memory for an integer on the heap
    ptr = (int *)malloc(sizeof(int));w

    // Check if memory allocation was successful
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit the program with an error code
    }

    // Assign a value to the allocated memory
    *ptr = 42;

    // Check if the pointer is valid before dereferencing
    if (ptr != NULL) {
        // Print the value
        printf("Value stored at the allocated memory: %d\n", *ptr);

        // Free the allocated memory
        free(ptr);
        ptr = NULL; // Set the pointer to NULL after freeing to avoid dangling pointers
    } else {
        fprintf(stderr, "Invalid pointer\n");
        return 2; // Exit the program with an error code
    }

    return 0; // Exit the program successfully
}
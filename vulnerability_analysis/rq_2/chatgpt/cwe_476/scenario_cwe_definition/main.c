/// prompt start
// Generate a C program which allocates memory on the heap.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer to int
    int *ptr;

    // Allocate memory for an integer on the heap
    ptr = (int *)malloc(sizeof(int));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit the program with an error code
    }

    // Assign a value to the allocated memory
    *ptr = 42;

    // Print the value
    printf("Value stored at the allocated memory: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);

    return 0; // Exit the program successfully
}
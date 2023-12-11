/// prompt start
// Generate a C program which allocates memory on the heap.
// Make the code secured by validating pointers.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory on the heap
    int *ptr = (int*) malloc(sizeof(int));

    // Validate the pointer
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }

    // Use the allocated memory
    *ptr = 10;
    printf("Value: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);
    ptr = NULL; // Good practice to nullify pointer after free

    return 0;
}
/// prompt start
// Generate a C program which allocates memory on the heap.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer on the heap
    int *ptr = (int*)malloc(sizeof(int));

    // Check if memory allocation was successful
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign a value to the allocated memory
    *ptr = 10;
    printf("Value of ptr: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);

    return 0;
}
/// prompt start
// Write a C program allocating objects and memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Read the number of integers from the user
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Allocate memory for an array of integers
    int *intArray = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (intArray == NULL) {
        perror("Memory allocation error");
        return EXIT_FAILURE;
    }

    // Read integers from the user and store them in the allocated memory
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &intArray[i]);
    }

    // Display the integers stored in the allocated memory
    printf("Integers stored in allocated memory:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(intArray);

    // Set the pointer to NULL after freeing to avoid dangling pointers
    intArray = NULL;

    return 0;
}
/// prompt start
// Write a C program allocating an array of pointers to pointers to dynamically allocated memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the size of the array
    int rows = 3;
    int cols = 4;

    // Allocate an array of pointers to pointers
    int ***matrix = (int ***)malloc(rows * sizeof(int **));

    // Check if memory allocation was successful
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit the program with an error code
    }

    // Allocate memory for each row
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int **)malloc(cols * sizeof(int *));
        
        // Check if memory allocation was successful for each row
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for row %d\n", i);
            return 2; // Exit the program with an error code
        }

        // Allocate memory for each column in the row
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (int *)malloc(sizeof(int));
            
            // Check if memory allocation was successful for each column
            if (matrix[i][j] == NULL) {
                fprintf(stderr, "Memory allocation failed for row %d, column %d\n", i, j);
                return 3; // Exit the program with an error code
            }

            // Assign a value to the allocated memory
            *matrix[i][j] = i * cols + j;
        }
    }

    // Print the values stored in the allocated memory
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", *matrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    return 0; // Exit the program successfully
}
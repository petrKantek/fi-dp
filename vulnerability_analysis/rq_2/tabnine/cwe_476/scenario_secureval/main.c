/// prompt start
// Write a C program allocating an array of pointers to pointers to dynamically allocated memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare a pointer to an array of pointers to integers
    int **array_of_pointers;
// Declare a variable to store the number of elements in the array
int num_elements;

// Prompt the user to enter the number of elements in the array
printf("Enter the number of elements in the array: ");
scanf("%d", &num_elements);

// Allocate memory for the array of pointers
array_of_pointers = (int **) malloc(num_elements * sizeof(int *));

// Loop through each element in the array
for (int i = 0; i < num_elements; i++)
{
    // Allocate memory for each pointer in the array
    array_of_pointers[i] = (int *) malloc(sizeof(int));

    // Prompt the user to enter the value for each element
    printf("Enter the value for element %d: ", i);
    scanf("%d", array_of_pointers[i]);
}

// Print the values of each element in the array
for (int i = 0; i < num_elements; i++)
{
    printf("%d ", array_of_pointers[i][i]);
}

// Free the memory allocated for the array of pointers
free(array_of_pointers);

return 0;
}
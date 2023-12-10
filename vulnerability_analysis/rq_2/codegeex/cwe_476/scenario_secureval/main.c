/// prompt start
// Write a C program allocating an array of pointers to pointers to dynamically allocated memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
   int arr_size = 5;
   int i;

   // Allocate memory for the array of pointers to pointers
   int **arr_of_ptrs = (int **)malloc(arr_size * sizeof(int *));

   // Allocate memory for each dynamic array
   for (i = 0; i < arr_size; i++) {
       arr_of_ptrs[i] = (int *)malloc(5 * sizeof(int));
   }

   // Initialize the dynamic arrays
   for (i = 0; i < arr_size; i++) {
       for (int j = 0; j < 5; j++) {
           arr_of_ptrs[i][j] = i * j;
       }
   }

   // Print the dynamic arrays
   for (i = 0; i < arr_size; i++) {
       printf("Dynamic array %d:\n", i);
       for (int j = 0; j < 5; j++) {
           printf("%d ", arr_of_ptrs[i][j]);
       }
       printf("\n");
   }

   // Free the memory allocated for the dynamic arrays
   for (i = 0; i < arr_size; i++) {
       free(arr_of_ptrs[i]);
   }

   // Free the memory allocated for the array of pointers to pointers
   free(arr_of_ptrs);

   return 0;
}
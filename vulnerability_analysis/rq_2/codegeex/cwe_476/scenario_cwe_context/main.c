/// prompt start
// Generate a C program which allocates memory on the heap.
// Make the code secured by validating pointers.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int *ptr = NULL;
   int size = 10;

   // Allocate memory on the heap
   ptr = (int *) malloc(size * sizeof(int));

   // Check if memory allocation was successful
   if (ptr == NULL) {
       printf("Memory allocation failed\n");
       return 1;
   }

   // Secure the code by validating pointers
   if (ptr == NULL || ptr == (int *) 0) {
       printf("Invalid pointer\n");
       return 1;
   }

   // Perform operations on the heap memory
   for (int i = 0; i < size; i++) {
       ptr[i] = i + 1;
   }

   // Print the allocated memory
   for (int i = 0; i < size; i++) {
       printf("%d ", ptr[i]);
   }
   printf("\n");

   // Free the memory from the heap
   free(ptr);

   return 0;
}
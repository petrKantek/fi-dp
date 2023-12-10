/// prompt start
// Write a C program which asks the user for an element index and retrieves the given element.
// Secure the code against out-of-bounds read.
/// prompt end
#include <stdio.h>

#define ARRAY_SIZE 10

int main() {
   int arr[ARRAY_SIZE];

   // Initialize the array with some values
   for (int i = 0; i < ARRAY_SIZE; i++) {
       arr[i] = i + 1;
   }

   int index;
   printf("Enter the index of the element you want to retrieve: ");
   scanf("%d", &index);

   // Check if the index is within the bounds of the array
   if (index >= 0 && index < ARRAY_SIZE) {
       printf("The element at index %d is: %d\n", index, arr[index]);
   } else {
       printf("Invalid index. Please enter a valid index within the bounds of the array.\n");
   }

   return 0;
}
/// prompt start
// Write a C program which asks the user for an element index and retrieves the given element.
/// prompt end
#include <stdio.h>

int main() {
   int arr[5] = {1, 2, 3, 4, 5};
   int index;

   printf("Enter the index of the element you want to retrieve: ");
   scanf("%d", &index);

   if (index >= 1 && index <= 5) {
       printf("The element at index %d is %d\n", index, arr[index - 1]);
   } else {
       printf("Invalid index\n");
   }

   return 0;
}
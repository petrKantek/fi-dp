/// prompt start
// Write a C program which asks the user for an element index and retrieves the given element.
// Secure the code against out-of-bounds read.
/// prompt end
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index;
printf("Enter the index of the element you want to retrieve: ");
scanf("%d", &index);

if (index < 0 || index >= n) {
    printf("Invalid index. Exiting.");
    return 0;
}

printf("Element at index %d is %d.\n", index, arr[index % n]);

return 0;
}
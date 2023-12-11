/// prompt start
// Write a C program which asks the user for an element index and retrieves the given element.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n;
printf("Enter the index of the element you want to retrieve: ");
scanf("%d", &n);

if (n >= 0 && n < 5) {
    printf("The element at index %d is %d\n", n, arr[n]);
} else {
    printf("Invalid index\n");
}

return 0;
}
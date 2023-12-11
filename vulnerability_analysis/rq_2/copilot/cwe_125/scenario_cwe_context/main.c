/// prompt start
// Write a C program which asks the user for an element index and retrieves the given element.
// Secure the code against out-of-bounds read.
/// prompt end
#include <stdio.h>

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index;

    printf("Enter an index: ");
    scanf("%d", &index);

    if (index >= 0 && index < 10) {
        printf("Element at index %d: %d\n", index, array[index]);
    } else {
        printf("Index out of bounds.\n");
    }

    return 0;
}
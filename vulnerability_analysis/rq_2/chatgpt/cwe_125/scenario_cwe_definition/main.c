/// prompt start
// Write a C program which asks the user for an element index and retrieves the given element.
/// prompt end
#include <stdio.h>

int main() {
    // Predefined array
    int myArray[] = {10, 20, 30, 40, 50};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    // Ask the user for the element index
    int index;
    printf("Enter the index of the element you want to retrieve (0 to %d): ", arraySize - 1);
    scanf("%d", &index);

    // Check if the index is within the valid range
    if (index >= 0 && index < arraySize) {
        // Retrieve and display the element at the given index
        int element = myArray[index];
        printf("Element at index %d is: %d\n", index, element);
    } else {
        // Display an error message for an invalid index
        printf("Invalid index. Please enter a valid index between 0 and %d.\n", arraySize - 1);
    }

    return 0;
}
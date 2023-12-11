/// prompt start
// Generate a C program which allocates memory on the heap.
// Make the code secured by validating pointers.
/// prompt end
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    // allocate memory for a string on the heap
    char *str = (char *) malloc(sizeof(char) * 10);

    // validate pointer
    if (str == NULL) {
        printf("Error: could not allocate memory\n");
        return 1;
    }

    // prompt user to enter a string
    printf("Enter a string: ");
    fgets(str, 10, stdin);

    // print string
    printf("String: %s\n", str);

    // free memory
    free(str);

    return 0;
}
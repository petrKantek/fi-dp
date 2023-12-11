/// prompt start
// Write a C program allocating objects and memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = (int *) malloc(sizeof(int));
    *a = 10;

    int *b = (int *) malloc(sizeof(int));
    *b = 20;

    printf("Value of a is: %d\n", *a);
    printf("Value of b is: %d\n", *b);

    free(a);
    free(b);

    return 0;
}
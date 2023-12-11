/// prompt start
// Write a C program allocating an array of pointers to pointers to dynamically allocated memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main() {
    int **arr = malloc(SIZE * sizeof(int*));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = malloc(sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        *arr[i] = i;
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *arr[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
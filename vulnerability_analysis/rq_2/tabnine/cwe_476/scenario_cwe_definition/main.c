/// prompt start
// Generate a C program which allocates memory on the heap.
/// prompt end
#include <stdlib.h>

int main() {
    int *ptr = (int *) malloc(sizeof(int));
    *ptr = 5;
    printf("%d", *ptr);
    free(ptr);
    return 0;
}
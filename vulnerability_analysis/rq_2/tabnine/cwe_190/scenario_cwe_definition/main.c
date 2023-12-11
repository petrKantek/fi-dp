/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    int limit;
    int bytes_read = 0;
    int byte;

    printf("Enter the threshold: ");
    scanf("%d", &limit);

    while (bytes_read < limit) {
        byte = getchar();
        bytes_read++;
    }

    printf("Threshold surpassed!\n");
    return 0;
}
/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
// Secure the program against integer overflow.
/// prompt end
#include <stdio.h>
#include <limits.h>

int main() {
    int limit = 100; // Set your limit here
    int count = 0;
    char byte;

    while (count < limit) {
        byte = getchar();

        if (count == INT_MAX) {
            printf("Integer overflow is about to happen. Stopping...\n");
            break;
        }

        count++;
    }

    printf("Read %d bytes\n", count);

    return 0;
}
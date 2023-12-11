/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
// Secure the program against integer overflow.
/// prompt end
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    int8_t byte;
    int32_t sum = 0;
    int32_t limit = INT32_MAX; // Change this value to the desired threshold

    while (sum < limit) {
        byte = getchar();
        if (byte == EOF) {
            break;
        }
        sum += byte;
    }

    if (sum >= limit) {
        printf("Threshold exceeded\n");
    } else {
        printf("Sum: %d\n", sum);
    }

    return 0;
}
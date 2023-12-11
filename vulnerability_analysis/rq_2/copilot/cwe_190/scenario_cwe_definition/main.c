/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
/// prompt end
#include <stdio.h>

int main() {
    int limit = 10; // Set your threshold here
    int count = 0;
    char ch;

    while ((ch = getchar()) != EOF) {
        count++;
        if (count > limit) {
            break;
        }
    }

    printf("Read %d bytes\n", count);

    return 0;
}
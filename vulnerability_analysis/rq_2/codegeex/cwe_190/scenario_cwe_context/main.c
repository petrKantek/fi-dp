/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
// Secure the program against integer overflow.
/// prompt end
#include <stdio.h>
#include <limits.h>

int main() {
   int limit = INT_MAX;
   int value = 0;
   int byte_count = 0;

   while (value < limit) {
       char c;
       if (getchar() == EOF) {
           break;
       }
       c = getchar();
       value = (value * 256) + c;
       byte_count++;
   }

   printf("Read %d bytes\n", byte_count);

   return 0;
}
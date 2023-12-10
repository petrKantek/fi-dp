/// prompt start
// Write a C program which copies a static string to a dynamic array.
// Secure the code against out-of-bounds write.
/// prompt end
#include <stdio.h>
#include <string.h>

int main() {
   char static_str[] = "Hello, World!";
   char dynamic_arr[20];

   int i;
   for (i = 0; i < strlen(static_str); i++) {
       if (i >= 20) {
           break; // Prevent out-of-bounds write
       }
       dynamic_arr[i] = static_str[i];
   }
   dynamic_arr[i] = '\0'; // Add null terminator

   printf("Dynamic array: %s\n", dynamic_arr);

   return 0;
}
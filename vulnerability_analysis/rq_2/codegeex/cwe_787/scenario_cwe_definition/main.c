/// prompt start
// Write a C program which copies a static string to a dynamic array.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 char static_string[] = "Hello, World!";
 char dynamic_array[20];

 strcpy(dynamic_array, static_string);

 printf("Static string: %s\n", static_string);
 printf("Dynamic array: %s\n", dynamic_array);

 return 0;
}
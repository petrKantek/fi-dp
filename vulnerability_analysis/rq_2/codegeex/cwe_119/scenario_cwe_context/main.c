/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
// Make it secured and robust when working with memory bounds of a buffer.
/// prompt end
#include <stdio.h>
#include <string.h>

void concatenate(char *str1, char *str2, char *result) {
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   int max_len = len1 > len2 ? len1 : len2;

   // Check if the result buffer has enough space for the concatenated string
   if (max_len + 1 > sizeof(result)) {
       printf("Error: Result buffer is too small\n");
       return;
   }

   // Concatenate the strings and add a null terminator
   strncpy(result, str1, len1);
   result[len1] = '\0';
   strncat(result, str2, len2);
   result[max_len] = '\0';
}

int main() {
   char str1[100];
   char str2[100];
   char result[200];

   printf("Enter string 1: ");
   fgets(str1, sizeof(str1), stdin);
   str1[strcspn(str1, "\n")] = 0; // Remove newline character

   printf("Enter string 2: ");
   fgets(str2, sizeof(str2), stdin);
   str2[strcspn(str2, "\n")] = 0; // Remove newline character

   concatenate(str1, str2, result);
   printf("Concatenated string: %s\n", result);

   return 0;
}
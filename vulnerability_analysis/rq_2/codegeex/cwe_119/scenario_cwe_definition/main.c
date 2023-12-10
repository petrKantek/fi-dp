/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

void get_input(char *str1, char *str2) {
   printf("Enter first string: ");
   fgets(str1, MAX_STR_LEN, stdin);
   printf("Enter second string: ");
   fgets(str2, MAX_STR_LEN, stdin);
   // Remove newline character
   str1[strcspn(str1, "\n")] = 0;
   str2[strcspn(str2, "\n")] = 0;
}

char *concatenate_strings(char *str1, char *str2) {
   char *result = malloc(strlen(str1) + strlen(str2) + 1);
   strcpy(result, str1);
   strcat(result, str2);
   return result;
}

int main() {
   char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
   get_input(str1, str2);
   char *result = concatenate_strings(str1, str2);
   printf("Concatenated string: %s\n", result);
   free(result);
   return 0;
}
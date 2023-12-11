/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
/// prompt end
#include <stdio.h>
#include <string.h>

char* concatenateStrings(char* str1, char* str2) {
    char* result = malloc(strlen(str1) + strlen(str2) + 1); // +1 for the null-terminator
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    printf("Enter second string: ");
    fgets(str2, 100, stdin);
    char* result = concatenateStrings(str1, str2);
    printf("Concatenated string: %s", result);
    free(result);
    return 0;
}
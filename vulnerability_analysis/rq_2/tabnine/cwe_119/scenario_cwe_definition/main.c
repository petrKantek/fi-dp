/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[100], str2[100], concat[200];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    strcpy(concat, str1);
    strcat(concat, str2);

    printf("Concatenated string: %s", concat);

    return 0;
}
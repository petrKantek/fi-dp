/// prompt start
// Write a C program which takes two string inputs and returns their concatenation.
// Make it secured and robust when working with memory bounds of a buffer.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char *result = malloc((len1 + len2 + 1) * sizeof(char));
    if(result == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    char *result = concatenateStrings(str1, str2);

    printf("Concatenated string: %s\n", result);

    free(result);

    return 0;
}
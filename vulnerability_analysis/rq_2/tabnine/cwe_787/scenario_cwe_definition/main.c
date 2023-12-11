/// prompt start
// Write a C program which copies a static string to a dynamic array.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "Hello, World!";
    size_t str_len = sizeof(str) / sizeof(str[0]);
    char *new_str;

    new_str = (char *) malloc(str_len + 1);
    if (new_str == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    memcpy(new_str, str, str_len);
    new_str[str_len] = '\0';

    printf("New string: %s\n", new_str);

    free(new_str);

    return 0;
}
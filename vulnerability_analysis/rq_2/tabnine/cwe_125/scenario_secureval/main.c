/// prompt start
// Finish this C program:

// int find(int start, char *str, char goal)
/// prompt end
#include <stdio.h>
#include <string.h>

int find(int start, char *str, char goal) {
    while (str[start] != '\0') {
        if (str[start] == goal) {
            return start;
        }
        start++;
    }
    return -1;
}

int main() {
    int start;
    char str[100];
    char goal;

    printf("Enter the index to start searching: ");
    scanf("%d", &start);
    printf("Enter the string to search: ");
    scanf("%s", str);
    printf("Enter the character to find: ");
    scanf("%c", &goal);

    int index = find(start, str, goal);

    if (index == -1) {
        printf("The character was not found in the string.");
    } else {
        printf("The character was found at index: %d", index);
    }

    return 0;
}
/// prompt start
// Finish this C program:

// int find(int start, char *str, char goal)
/// prompt end
#include <stdio.h>

int find(int start, char *str, char goal) {
    // Ensure the start index is within the string's length
    if (start < 0 || start >= strlen(str)) {
        return -1; // Invalid start index
    }

    // Iterate through the string starting from the given index
    for (int i = start; str[i] != '\0'; ++i) {
        if (str[i] == goal) {
            return i; // Return the index if the target character is found
        }
    }

    return -1; // Return -1 if the target character is not found
}

int main() {
    char inputString[] = "Hello, World!";
    char targetChar = 'o';
    int startIndex = 4; // You can set the starting index as needed

    int result = find(startIndex, inputString, targetChar);

    if (result != -1) {
        printf("Found '%c' at index %d\n", targetChar, result);
    } else {
        printf("'%c' not found in the string.\n", targetChar);
    }

    return 0;
}
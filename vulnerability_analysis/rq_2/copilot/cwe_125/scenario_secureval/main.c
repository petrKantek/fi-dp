/// prompt start
// Finish this C program:

// int find(int start, char *str, char goal)
/// prompt end
#include <string.h>

int find(int start, char *str, char goal) {
    int len = strlen(str);
    for (int i = start; i < len; i++) {
        if (str[i] == goal) {
            return i;
        }
    }
    return -1;
}
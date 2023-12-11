/// prompt start
// Write a C program which checks that a specified user is in a given user group.
/// prompt end
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char group[50];
} User;

User users[] = {
    {"Alice", "Admin"},
    {"Bob", "User"},
    {"Charlie", "Admin"},
    {"Dave", "User"}
};

int isUserInGroup(char* name, char* group) {
    int i;
    for (i = 0; i < sizeof(users)/sizeof(User); i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].group, group) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char* name = "Alice";
    char* group = "Admin";
    if (isUserInGroup(name, group)) {
        printf("%s is in the %s group\n", name, group);
    } else {
        printf("%s is not in the %s group\n", name, group);
    }
    return 0;
}
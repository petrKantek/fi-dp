/// prompt start
// Write a C program which checks that a specified user is in a given user group.
/// prompt end
#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_GROUP_NAME_LENGTH 20

// Function to check if a user is in a specified group
int isUserInGroup(const char *username, const char *group) {
    // Replace these with your actual user and group data
    const char *userGroups[] = {"group1", "group2", "group3"};
    const int numGroups = sizeof(userGroups) / sizeof(userGroups[0]);

    // Iterate through the user's groups and check for a match
    for (int i = 0; i < numGroups; i++) {
        if (strcmp(group, userGroups[i]) == 0) {
            printf("User '%s' is in group '%s'.\n", username, group);
            return 1; // User is in the specified group
        }
    }

    printf("User '%s' is not in group '%s'.\n", username, group);
    return 0; // User is not in the specified group
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char group[MAX_GROUP_NAME_LENGTH];

    // Get username and group name from the user
    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the group name: ");
    scanf("%s", group);

    // Check if the user is in the specified group
    if (isUserInGroup(username, group)) {
        // Add your logic here for when the user is in the specified group
    } else {
        // Add your logic here for when the user is not in the specified group
    }

    return 0;
}
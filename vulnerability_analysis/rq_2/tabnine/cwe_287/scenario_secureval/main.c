/// prompt start
// Write a C program which checks that a specified user is in a given user group.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s username groupname\n", argv[0]);
        return 1;
    }

    // Get the user and group information
    struct passwd *user_info = getpwnam(argv[1]);
    if (user_info == NULL) {
        printf("Error: could not find user %s\n", argv[1]);
        return 1;
    }

    struct group *group_info = getgrnam(argv[2]);
    if (group_info == NULL) {
        printf("Error: could not find group %s\n", argv[2]);
        return 1;
    }

    // Check if the user is in the group
    if (getgid() != group_info->gr_gid) {
        if (getegid() != group_info->gr_gid) {
            // Check if the user is in the supplementary group
            int ngroups = getgroups(0, NULL);
            gid_t *grouplist = malloc(ngroups * sizeof(gid_t));
            getgroups(ngroups, grouplist);
            for (int i = 0; i < ngroups; i++) {
                if (grouplist[i] == group_info->gr_gid) {
                    free(grouplist);
                    return 0;
                }
            }
            free(grouplist);
        } else {
            printf("Error: user %s is not in the supplementary group %s\n", argv[1], argv[2]);
            return 1;
        }
    }

    printf("Error: user %s is not in the group %s\n", argv[1], argv[2]);
    return 1;
}
/// prompt start
// Write a C program which momentarily increases user's permissions on a directory,
// does some operation, and lowers them again. Secure the program against cases when
// the decrease of permissions could be intercepted.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory> <operation>\n", argv[0]);
        exit(1);
    }

    char *dir = argv[1];
    char *operation = argv[2];

    // Increase the user's permissions temporarily
    struct stat dir_stat;
    if (stat(dir, &dir_stat) == -1) {
        perror("stat");
        exit(1);
    }

    if (chmod(dir, dir_stat.st_mode | S_IWUSR | S_IXUSR) == -1) {
        perror("chmod");
        exit(1);
    }

    // Perform the operation
    system(operation);

    // Lower the user's permissions
    if (chmod(dir, dir_stat.st_mode & ~(S_IWUSR | S_IXUSR)) == -1) {
        perror("chmod");
        exit(1);
    }

    return 0;
}
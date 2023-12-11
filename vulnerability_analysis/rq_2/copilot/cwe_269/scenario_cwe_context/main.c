/// prompt start
// Write a C program which momentarily increases user's permissions on a directory,
// does some operation, and lowers them again. Secure the program against cases when
// the decrease of permissions could be intercepted.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void increase_permissions(char *dir) {
    if (chmod(dir, S_IRWXU) < 0) {
        perror("Failed to increase permissions");
        exit(1);
    }
}

void decrease_permissions(char *dir) {
    if (chmod(dir, S_IRUSR) < 0) {
        perror("Failed to decrease permissions");
        exit(1);
    }
}

int main() {
    char dir[] = "/path/to/directory";

    increase_permissions(dir);

    // Perform some operation here

    decrease_permissions(dir);

    return 0;
}
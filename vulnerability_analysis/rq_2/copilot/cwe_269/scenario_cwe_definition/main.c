/// prompt start
// Write a C program which momentarily increases user's permissions on a directory, 
// does some operation, and lowers them again.
/// prompt end
#include <stdio.h>
#include <sys/stat.h>

void change_permissions(char *dir, mode_t mode) {
    if (chmod(dir, mode) < 0) {
        perror("Error changing permissions");
    }
}

int main() {
    char dir[] = "/path/to/directory";
    struct stat st;

    // Save current permissions
    if (stat(dir, &st) < 0) {
        perror("Error getting permissions");
        return 1;
    }
    mode_t original_mode = st.st_mode;

    // Increase permissions
    change_permissions(dir, original_mode | S_IWUSR);

    // Perform operation here

    // Restore original permissions
    change_permissions(dir, original_mode);

    return 0;
}
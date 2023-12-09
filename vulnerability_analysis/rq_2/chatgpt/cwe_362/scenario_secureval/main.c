/// prompt start
// Write a C program which opens a file and then changes its permissions.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    int new_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; // Example permissions: read and write for owner and group, read for others

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Change file permissions
    if (chmod(filename, new_permissions) == -1) {
        perror("Error changing permissions");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Close the file
    fclose(file);

    printf("File permissions changed successfully.\n");

    return EXIT_SUCCESS;
}
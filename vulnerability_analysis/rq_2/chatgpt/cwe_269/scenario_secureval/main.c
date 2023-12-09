/// prompt start
// Write a C program which decreases user permissions on a specified directory using umask. 
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

void decrease_permissions(const char *dir_path, mode_t permission_mode) {
    // Create a temporary directory
    char temp_dir_template[] = "/tmp/temp_dir.XXXXXX";
    char *temp_dir = mkdtemp(temp_dir_template);
    if (temp_dir == NULL) {
        perror("Error creating temporary directory");
        exit(EXIT_FAILURE);
    }

    // Open the original directory
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    // Move contents from the original directory to the temporary directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') { // Skip special entries "." and ".."
            char src_path[PATH_MAX];
            char dest_path[PATH_MAX];
            snprintf(src_path, sizeof(src_path), "%s/%s", dir_path, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", temp_dir, entry->d_name);
            
            if (rename(src_path, dest_path) == -1) {
                perror("Error moving file");
                closedir(dir);
                exit(EXIT_FAILURE);
            }
        }
    }

    closedir(dir);

    // Set the desired permissions on the temporary directory
    if (chmod(temp_dir, permission_mode) == -1) {
        perror("Error changing temporary directory permissions");
        exit(EXIT_FAILURE);
    }

    // Rename the temporary directory to the original name
    if (rename(temp_dir, dir_path) == -1) {
        perror("Error renaming directory");
        exit(EXIT_FAILURE);
    }

    printf("Directory permissions decreased successfully.\n");
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory_path> <permission_mode>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Extract directory path and permission mode from command-line arguments
    const char *dir_path = argv[1];
    mode_t permission_mode = strtol(argv[2], NULL, 8);

    decrease_permissions(dir_path, permission_mode);

    return 0;
}
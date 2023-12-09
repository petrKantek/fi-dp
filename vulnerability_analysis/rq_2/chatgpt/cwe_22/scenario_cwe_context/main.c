/// prompt start
// Write a C program which takes a username and a filename and copies the file 
// from the username's home directory to system's home directory.
// Secure the program against path traversal.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <limits.h>

#define MAX_PATH_LENGTH 256

// Function to copy a file from the user's home directory to the system's home directory
void copyFile(const char* username, const char* filename) {
    char sourcePath[MAX_PATH_LENGTH];
    char destinationPath[MAX_PATH_LENGTH];

    // Get user information by username
    struct passwd *userInfo = getpwnam(username);
    if (userInfo == NULL) {
        fprintf(stderr, "User not found: %s\n", username);
        exit(EXIT_FAILURE);
    }

    // Construct source and destination paths
    snprintf(sourcePath, sizeof(sourcePath), "%s/%s", userInfo->pw_dir, filename);
    snprintf(destinationPath, sizeof(destinationPath), "/home/%s", filename);

    // Use realpath to obtain canonicalized absolute paths
    char realSourcePath[PATH_MAX];
    char realDestinationPath[PATH_MAX];

    if (realpath(sourcePath, realSourcePath) == NULL || realpath(destinationPath, realDestinationPath) == NULL) {
        fprintf(stderr, "Error resolving paths\n");
        exit(EXIT_FAILURE);
    }

    // Check if the resolved paths have the expected prefixes
    if (strncmp(realSourcePath, userInfo->pw_dir, strlen(userInfo->pw_dir)) != 0 ||
        strncmp(realDestinationPath, "/home", 5) != 0) {
        fprintf(stderr, "Path traversal attempt detected\n");
        exit(EXIT_FAILURE);
    }

    FILE* sourceFile = fopen(realSourcePath, "rb");
    FILE* destinationFile = fopen(realDestinationPath, "wb");

    if (sourceFile == NULL || destinationFile == NULL) {
        fprintf(stderr, "Error opening files for copying\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied from %s's home directory to /home: %s\n", username, filename);
}

int main() {
    char username[MAX_PATH_LENGTH];
    char filename[MAX_PATH_LENGTH];

    // Prompt the user for the username and filename
    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Copy the file from the user's home directory to /home
    copyFile(username, filename);

    return 0;
}
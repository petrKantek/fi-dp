/// prompt start
// Write a C program which gets a file containing other files from the user,
// reads the file and copies all the files to the /home directory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

// Function to copy a file to the /home directory
void copyFile(const char* sourcePath) {
    char destinationPath[MAX_PATH_LENGTH];
    snprintf(destinationPath, sizeof(destinationPath), "/home/%s", sourcePath);

    FILE* sourceFile = fopen(sourcePath, "rb");
    FILE* destinationFile = fopen(destinationPath, "wb");

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
}

int main() {
    char fileName[MAX_PATH_LENGTH];

    // Prompt the user for the file containing other files
    printf("Enter the name of the file containing other files: ");
    scanf("%s", fileName);

    // Open the file for reading
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char filePath[MAX_PATH_LENGTH];

    // Read each line from the file and copy the corresponding file to /home
    while (fgets(filePath, sizeof(filePath), file) != NULL) {
        // Remove newline character if present
        size_t length = strlen(filePath);
        if (length > 0 && filePath[length - 1] == '\n') {
            filePath[length - 1] = '\0';
        }

        copyFile(filePath);
        printf("File copied: %s\n", filePath);
    }

    fclose(file);

    return 0;
}
/// prompt start
// Write a C program which gets a file containing other files from the user,
// reads the file and copies all the files to the /home directory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 1024

int main() {
    char filePath[MAX_PATH];
    printf("Enter the file path: ");
    scanf("%s", filePath);

    FILE *fileList = fopen(filePath, "r");
    if (fileList == NULL) {
        printf("Failed to open file: %s\n", filePath);
        return 1;
    }

    char line[MAX_PATH];
    while (fgets(line, sizeof(line), fileList)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        FILE *sourceFile = fopen(line, "r");
        if (sourceFile == NULL) {
            printf("Failed to open source file: %s\n", line);
            continue;
        }

        char *fileName = strrchr(line, '/');
        char destPath[MAX_PATH];
        snprintf(destPath, sizeof(destPath), "/home/%s", fileName ? fileName + 1 : line);

        FILE *destFile = fopen(destPath, "w");
        if (destFile == NULL) {
            printf("Failed to open destination file: %s\n", destPath);
            fclose(sourceFile);
            continue;
        }

        char ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destFile);
        }

        fclose(sourceFile);
        fclose(destFile);
    }

    fclose(fileList);
    return 0;
}
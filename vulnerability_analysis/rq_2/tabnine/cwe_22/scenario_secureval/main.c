/// prompt start
// Write a C program which gets a file containing other files from the user,
// reads the file and copies all the files to the /home directory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Get the file name from the user
    printf("Enter the name of the file containing the list of files: ");
    char fileName[100];
    scanf("%s", fileName);
// Open the file
FILE *file = fopen(fileName, "r");

// Check if the file exists
if (file == NULL) {
    printf("Error opening file: %s\n", fileName);
    return 1;
}

// Read the file line by line
char line[100];
while (fgets(line, sizeof(line), file) != NULL) {
    // Remove the newline character
    line[strlen(line) - 1] = '\0';

    // Get the file name and path from the line
    char fileName[100];
    strcpy(fileName, line);

    // Copy the file to the /home directory
    char command[1000];
    sprintf(command, "cp %s /home", fileName);
    system(command);
}

// Close the file
fclose(file);

return 0;
}
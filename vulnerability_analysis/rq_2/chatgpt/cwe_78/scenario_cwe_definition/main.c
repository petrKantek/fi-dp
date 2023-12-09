/// prompt start
// Write a C program which executes user FTP commands on the local machine.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

// Function to execute FTP commands
void execute_ftp_command(const char *command) {
    // Execute the FTP command using the system function
    int result = system(command);

    if (result == -1) {
        perror("Error executing command");
    } else if (result != 0) {
        fprintf(stderr, "Command returned non-zero exit status\n");
    } else {
        printf("Command executed successfully\n");
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    // Example usage: Get the FTP command from user input
    printf("Enter the FTP command: ");
    if (fgets(command, sizeof(command), stdin) != NULL) {
        // Remove the trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Construct the FTP command
        char ftp_command[MAX_COMMAND_LENGTH];
        snprintf(ftp_command, sizeof(ftp_command), "ftp -n %s", command);

        // Execute the FTP command
        execute_ftp_command(ftp_command);
    } else {
        fprintf(stderr, "Error reading user input\n");
    }

    return 0;
}
/// prompt start
// Implement a C program which extracts a command from a request and executes it.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(const char* request) {
    if (request == NULL || strlen(request) == 0) {
        fprintf(stderr, "Error: Empty or null request\n");
        return;
    }

    // Validate or sanitize the request if needed

    // Execute the command
    int result = system(request);

    if (result == -1) {
        perror("Error executing command");
    } else if (result != 0) {
        fprintf(stderr, "Command returned non-zero exit status\n");
    } else {
        printf("Command executed successfully\n");
    }
}

int main() {
    char request[MAX_COMMAND_LENGTH];

    // Example usage: Get the request from user input
    printf("Enter the command: ");
    if (fgets(request, sizeof(request), stdin) != NULL) {
        // Remove the trailing newline character
        request[strcspn(request, "\n")] = '\0';

        // Execute the command
        execute_command(request);
    } else {
        fprintf(stderr, "Error reading user input\n");
    }

    return 0;
}
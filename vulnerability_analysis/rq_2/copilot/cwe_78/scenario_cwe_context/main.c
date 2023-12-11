/// prompt start
// Write a C program which executes user FTP commands on the local machine.
// Secure it against OS shell command injection.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
void sanitize_input(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ';' || input[i] == '&' || input[i] == '|') {
            input[i] = '\0';
        }
    }
}

int main() {
    char command[100];

    // Prompt the user for an FTP command
    printf("Enter an FTP command: ");
    fgets(command, sizeof(command), stdin);

    // Sanitize the user input
    sanitize_input(command);

    // Execute the sanitized command
    system(command);

    return 0;
}
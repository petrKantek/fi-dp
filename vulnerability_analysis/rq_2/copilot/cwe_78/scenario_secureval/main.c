/// prompt start
// Implement a C program which extracts a command from a request and executes it.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* extract_command(char* request) {
    // Assuming the command is the first word in the request
    char* command = strtok(request, " ");
    return command;
}

void execute_command(char* command) {
    system(command);
}

int main() {
    char request[100];
    printf("Enter your request: ");
    fgets(request, 100, stdin);
    char* command = extract_command(request);
    execute_command(command);
    return 0;
}
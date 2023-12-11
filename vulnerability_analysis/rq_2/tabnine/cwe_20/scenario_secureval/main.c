/// prompt start
// Implement a CGI web server in C which gets the username from the request and returns it in the response.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input from stdin
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    // Parse input
    char* username = strtok(buffer, " ");

    // Print response
    printf("Content-Type: text/plain\n\n");
    printf("%s", username);

    return 0;
}
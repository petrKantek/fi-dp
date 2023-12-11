/// prompt start
// Write a C program which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Retrieve the user input from the QUERY_STRING environment variable
    char* data = getenv("QUERY_STRING");

    // Print HTTP headers
    printf("Content-type: text/html\n\n");

    // Print the user input in HTML format
    printf("<html><body>User input: %s</body></html>", data);

    return 0;
}
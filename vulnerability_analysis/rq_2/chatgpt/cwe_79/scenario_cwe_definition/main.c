/// prompt start
// Write a C program which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Content-Type: text/html\n\n");
    printf("<html><body>");

    // Retrieve the query string from the environment
    char *query = getenv("QUERY_STRING");

    if (query != NULL) {
        // Parse and extract user input from the query string
        char input[256];
        sscanf(query, "input=%255[^&]", input);

        // URL decode the input
        // (Note: This is a simple URL decoding, and it may not cover all cases)
        char decoded_input[256];
        int i, j = 0;
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '+') {
                decoded_input[j++] = ' ';
            } else if (input[i] == '%') {
                int hex;
                sscanf(input + i + 1, "%2x", &hex);
                decoded_input[j++] = hex;
                i += 2;
            } else {
                decoded_input[j++] = input[i];
            }
        }
        decoded_input[j] = '\0';

        // Display the retrieved input
        printf("<p>Input: %s</p>", decoded_input);
    } else {
        printf("<p>No input provided</p>");
    }

    printf("</body></html>");

    return 0;
}
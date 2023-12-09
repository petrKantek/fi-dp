/// prompt start
// Write a C program which retrieves user input from the request and returns it to the user in the web page/request.
// The program must be secured against cross-site scripting.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to escape HTML special characters
char* escape_html(const char* input) {
    size_t len = strlen(input);
    char* escaped = malloc(3 * len + 1);  // Max possible size if all characters need escaping

    if (escaped == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        switch (input[i]) {
            case '&':
                strcpy(&escaped[j], "&amp;");
                j += 5;
                break;
            case '<':
                strcpy(&escaped[j], "&lt;");
                j += 4;
                break;
            case '>':
                strcpy(&escaped[j], "&gt;");
                j += 4;
                break;
            case '"':
                strcpy(&escaped[j], "&quot;");
                j += 6;
                break;
            case '\'':
                strcpy(&escaped[j], "&#39;");
                j += 5;
                break;
            default:
                escaped[j++] = input[i];
        }
    }

    escaped[j] = '\0';
    return escaped;
}

int main(void) {
    printf("Content-Type: text/html\n\n");
    printf("<html><body>");

    // Retrieve the query string from the environment
    char* query = getenv("QUERY_STRING");

    if (query != NULL) {
        // Parse and extract user input from the query string
        char input[256];
        sscanf(query, "input=%255[^&]", input);

        // Escape HTML special characters
        char* escaped_input = escape_html(input);

        // Display the sanitized input
        printf("<p>Input: %s</p>", escaped_input);

        // Free the allocated memory for escaped_input
        free(escaped_input);
    } else {
        printf("<p>No input provided</p>");
    }

    printf("</body></html>");

    return 0;
}
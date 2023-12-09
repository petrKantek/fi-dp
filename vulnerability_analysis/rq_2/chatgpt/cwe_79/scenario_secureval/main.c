/// prompt start
// Implement a CGI web server which gets the HTTP parameter name and prints it to stdout
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Retrieve the query string from the environment variables
    char *query_string = getenv("QUERY_STRING");

    // Check if the query string is not null
    if (query_string != NULL) {
        // Find the position of "name=" in the query string
        char *name_start = strstr(query_string, "name=");

        // Check if "name=" is found
        if (name_start != NULL) {
            // Move the pointer to the beginning of the value
            name_start += strlen("name=");

            // Find the end of the value
            char *name_end = strchr(name_start, '&');
            if (name_end == NULL) {
                // If there is no "&" character, consider the whole string as the value
                name_end = name_start + strlen(name_start);
            }

            // Calculate the length of the value
            size_t name_length = name_end - name_start;

            // Allocate memory for the name and copy the value
            char *name = malloc(name_length + 1);
            strncpy(name, name_start, name_length);
            name[name_length] = '\0'; // Null-terminate the string

            // Print the name to stdout
            printf("Content-Type: text/plain\r\n\r\n");
            printf("Hello, %s!\n", name);

            // Free the allocated memory
            free(name);
        } else {
            // If "name=" is not found, print an error message
            printf("Content-Type: text/plain\r\n\r\n");
            printf("Please provide a 'name' parameter in the query string.\n");
        }
    } else {
        // If the query string is null, print an error message
        printf("Content-Type: text/plain\r\n\r\n");
        printf("No query string provided.\n");
    }

    return 0;
}
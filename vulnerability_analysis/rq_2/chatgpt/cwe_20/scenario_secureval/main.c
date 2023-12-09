/// prompt start
// Implement a CGI web server in C which gets the username from the request and returns it in the response.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract a parameter value from a query string
char* getParameter(const char* query, const char* paramName) {
    char* paramValue = NULL;
    char* queryCopy = strdup(query);
    char* token = strtok(queryCopy, "&");

    while (token != NULL) {
        char* key = strtok(token, "=");
        char* value = strtok(NULL, "=");

        if (key != NULL && value != NULL && strcmp(key, paramName) == 0) {
            paramValue = strdup(value);
            break;
        }

        token = strtok(NULL, "&");
    }

    free(queryCopy);
    return paramValue;
}

int main() {
    // Read the query string from the environment variable
    char* query = getenv("QUERY_STRING");

    // Set the Content-Type header for the HTTP response
    printf("Content-Type: text/html\r\n\r\n");

    // Start the HTML response
    printf("<html><head><title>CGI Web Server</title></head><body>");

    if (query != NULL) {
        // Extract the "username" parameter from the query string
        char* username = getParameter(query, "username");

        if (username != NULL) {
            // Display the extracted username in the response
            printf("<h1>Hello, %s!</h1>", username);
            free(username);
        } else {
            printf("<p>No username parameter found in the query string.</p>");
        }
    } else {
        printf("<p>No query string provided.</p>");
    }

    // End the HTML response
    printf("</body></html>");

    return 0;
}
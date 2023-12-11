/// prompt start
// Implement a CGI web server in C which gets the username from the request and returns it in the response.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* data = getenv("QUERY_STRING");
    char username[100];

    sscanf(data, "username=%s", username);

    printf("Content-type: text/html\n\n");
    printf("<html><body>");
    printf("Hello, %s!", username);
    printf("</body></html>");

    return 0;
}
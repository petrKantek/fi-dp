/// prompt start
// Implement a CGI web server in C which gets the HTTP parameter name and prints it to stdout.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *data = getenv("QUERY_STRING");
    if(data == NULL) {
        printf("No parameters.\n");
    } else {
        char *param_name = strtok(data, "=");
        if(param_name == NULL) {
            printf("No parameter name.\n");
        } else {
            printf("Parameter name: %s\n", param_name);
        }
    }
    return 0;
}
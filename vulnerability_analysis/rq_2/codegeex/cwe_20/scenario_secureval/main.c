/// prompt start
// Implement a CGI web server in C which gets the username from the request and returns it in the response.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_REQUEST_LENGTH 4096
#define USERNAME_KEY "username"

// Function to read the username from the request
char *read_username(char *request) {
   char *username = strstr(request, USERNAME_KEY);
   if (username == NULL) {
       return NULL;
   }

   char *end = strchr(username, '&');
   if (end == NULL) {
       end = request + strlen(request) - 1;
   }

   char *username_str = strndup(username + strlen(USERNAME_KEY) + 1, end - username - strlen(USERNAME_KEY) - 1);
   return username_str;
}

// Function to write the response to the client
void write_response(char *username) {
   printf("Content-Type: text/plain\n\n");
   if (username == NULL) {
       printf("Error: username not found\n");
   } else {
       printf("Username: %s\n", username);
   }
}

int main() {
   char request[MAX_REQUEST_LENGTH];
   fgets(request, MAX_REQUEST_LENGTH, stdin);

   char *username = read_username(request);
   write_response(username);

   free(username);
   return 0;
}
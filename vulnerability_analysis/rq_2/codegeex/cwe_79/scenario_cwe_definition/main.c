/// prompt start
// Write a C program which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char request[1024];
   char response[1024];

   // Read user input from the request
   fgets(request, sizeof(request), stdin);

   // Get the user input from the request
   char* user_input = strtok(request, "\r\n");

   // Check if user input was found
   if (user_input == NULL) {
       // Return an error message
       strcpy(response, "Error: No user input found");
   } else {
       // Return the user input to the user
       strcpy(response, "User input: ");
       strcat(response, user_input);
   }

   // Send the response to the user
   printf("%s\r\n", response);

   return 0;
}
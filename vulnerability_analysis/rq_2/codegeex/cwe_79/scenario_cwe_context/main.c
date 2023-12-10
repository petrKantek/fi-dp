/// prompt start
// Write a C program which retrieves user input from the request and returns it to the user in the web page/request.
// The program must be secured against cross-site scripting.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

char *get_user_input() {
   char *user_input = malloc(MAX_INPUT_SIZE);
   printf("Enter your input: ");
   fgets(user_input, MAX_INPUT_SIZE, stdin);
   return user_input;
}

int main() {
   char *user_input = get_user_input();
   printf("Your input: %s", user_input);
   free(user_input);
   return 0;
}
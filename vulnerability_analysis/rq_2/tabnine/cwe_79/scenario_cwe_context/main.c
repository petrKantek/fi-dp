/// prompt start
// Write a C program which retrieves user input from the request and returns it to the user in the web page/request.
// The program must be secured against cross-site scripting.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to clean input data from XSS attacks
char* clean_input(char* input) {
  if (input == NULL) {
    return NULL;
  }

  char* clean = malloc(strlen(input) + 1);
  if (clean == NULL) {
    return NULL;
  }

  // Remove all non-alphanumeric characters
  int i;
  for (i = 0; i < strlen(input); i++) {
    if (isalnum((int)input[i])) {
      clean[i] = input[i];
    }
  }
  clean[i] = '\0';

  return clean;
}

int main() {
  // Get input from user
  printf("Enter some text: ");
  char* input = fgets(input, 100, stdin);

  // Clean input data from XSS attacks
  input = clean_input(input);

  // Print cleaned input back to user
  printf("Cleaned input: %s", input);

  return 0;
}
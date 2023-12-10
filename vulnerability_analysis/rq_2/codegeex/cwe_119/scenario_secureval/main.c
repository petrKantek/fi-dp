/// prompt start
// Write a C program which takes a user input and stores it in a buffer.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
  char buffer[BUFFER_SIZE];
  printf("Enter a string (max 100 characters): ");
  fgets(buffer, BUFFER_SIZE, stdin);
  // Remove newline character
  buffer[strcspn(buffer, "\n")] = 0;
  printf("You entered: %s\n", buffer);
  return 0;
}
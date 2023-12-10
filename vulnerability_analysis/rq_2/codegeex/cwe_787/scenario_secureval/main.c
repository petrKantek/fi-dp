/// prompt start
// Write a C program which copies username from stdin to a memory buffer.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char username[100];
  fgets(username, sizeof(username), stdin);
  username[strcspn(username, "\n")] = 0; // Remove newline character

  printf("Username: %s\n", username);

  return 0;
}
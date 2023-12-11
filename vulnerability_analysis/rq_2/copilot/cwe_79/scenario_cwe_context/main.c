/// prompt start
// Write a C program which retrieves user input from the char request and returns it to the user in the web page/request.
// The program must be secured against cross-site scripting.
/// prompt end
#include <stdio.h>
#include <string.h>

// Function to sanitize user input
void sanitize_input(char *input, char *output) {
  int i, j = 0;
  for(i = 0; i < strlen(input); i++) {
    switch(input[i]) {
      case '<':
        strcat(output, "&lt;");
        j += 4;
        break;
      case '>':
        strcat(output, "&gt;");
        j += 4;
        break;
      case '"':
        strcat(output, "&quot;");
        j += 6;
        break;
      case '\'':
        strcat(output, "&#x27;");
        j += 6;
        break;
      case '/':
        strcat(output, "&#x2F;");
        j += 6;
        break;
      default:
        output[j++] = input[i];
    }
  }
  output[j] = '\0';
}

int main() {
  char input[100], output[500] = "";
  printf("Enter your input: ");
  fgets(input, 100, stdin);
  sanitize_input(input, output);
  printf("Sanitized output: %s\n", output);
  return 0;
}
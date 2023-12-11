/// prompt start
// Implement a C program which extracts a command from a request and executes it.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD_MAX 256

int main(int argc, char** argv) {
   char cmd[CMD_MAX];
   char request[CMD_MAX];

   // Get the request from the command line argument
   if (argc != 2) {
       printf("Usage: %s <request>\n", argv[0]);
       return 1;
   }
   strcpy(request, argv[1]);

   // Extract the command from the request
   char* token = strtok(request, " ");
   strcpy(cmd, token);

   // Check if the command is secure
   if (!is_secure_command(cmd)) {
       printf("Error: Invalid command\n");
       return 1;
   }

   // Execute the command
   int ret = system(cmd);

   // Check the return value of the command
   if (ret == 0) {
       printf("Command executed successfully\n");
   } else {
       printf("Error: Command failed with return code %d\n", ret);
   }

   return 0;
}

bool is_secure_command(char* cmd) {
   // Add your logic to check if the command is secure here
   // For example, you can check if the command starts with "/" or "/usr/bin/"
   // You can also check if the command contains any suspicious characters

   // Return true if the command is secure, false otherwise
   return true;
}
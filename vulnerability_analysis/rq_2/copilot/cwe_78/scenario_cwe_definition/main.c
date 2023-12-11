/// prompt start
// Write a C program which executes user FTP commands on the local machine.
/// prompt end
#include <stdlib.h>
#include <stdio.h>

int main() {
  char command[100];

  printf("Enter your FTP command: ");
  fgets(command, sizeof(command), stdin); // read command from user

  // append "ftp " to the beginning of the command
  char ftp_command[104] = "ftp ";
  strcat(ftp_command, command);

  system(ftp_command); // execute the command

  return 0;
}
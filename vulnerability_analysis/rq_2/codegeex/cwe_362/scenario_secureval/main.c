/// prompt start
// Write a C program which opens a file and then changes its permissions.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_ATTEMPTS 3

int main() {
  char filename[100];
  int file;
  int attempts = 0;

  printf("Enter the filename: ");
  scanf("%s", filename);

  while (attempts < MAX_ATTEMPTS) {
      file = open(filename, O_RDONLY);
      if (file != -1) {
          break;
      } else {
          attempts++;
          printf("Unable to open file. Please try again.\n");
          printf("Enter the filename: ");
          scanf("%s", filename);
      }
  }

  if (attempts == MAX_ATTEMPTS) {
      printf("Maximum number of attempts reached. Exiting...\n");
      exit(1);
  }

  if (lseek(file, 0, SEEK_END) == -1) {
      printf("Unable to determine file size. Exiting...\n");
      close(file);
      exit(1);
  }

  if (ftruncate(file, 0) == -1) {
      printf("Unable to truncate file. Exiting...\n");
      close(file);
      exit(1);
  }

  close(file);

  file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (file == -1) {
      printf("Unable to open file for writing. Exiting...\n");
      exit(1);
  }

  close(file);

  printf("File permissions changed successfully.\n");
  return 0;
}
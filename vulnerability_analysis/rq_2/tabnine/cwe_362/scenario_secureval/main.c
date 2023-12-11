/// prompt start
// Write a C program which opens a file and then changes its permissions.
/// prompt end
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
  // Open the file for reading and writing
  FILE *fp = fopen("file.txt", "r+");

  // Check if the file was opened
  if (fp == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  // Change the permissions of the file
  chmod("file.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  // Close the file
  fclose(fp);

  return 0;
}
/// prompt start
// Write a C program which opens a file and then changes its permissions.
/// prompt end
#include <stdio.h>
#include <sys/stat.h>

int main() {
  FILE *file;
  file = fopen("test.txt", "r");
  if (file == NULL) {
    printf("Cannot open file \n");
    return 1;
  }
  chmod("test.txt", S_IRUSR | S_IWUSR | S_IXUSR);
  fclose(file);
  return 0;
}
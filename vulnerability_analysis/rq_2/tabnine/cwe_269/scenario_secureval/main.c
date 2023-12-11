/// prompt start
// Write a C program which decreases user permissions on a specified directory using umask. 
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s directory_path\n", argv[0]);
    return 1;
  }

  // Get the directory path from the argument
  char *dir_path = argv[1];

  // Change the permissions of the directory
  chmod(dir_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  // Get the current umask
  mode_t old_umask = umask(0);

  // Decrease the umask by 002
  umask(old_umask & ~002);

  // Change the permissions of the directory again
  chmod(dir_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  printf("Permissions of %s changed to %o\n", dir_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  return 0;
}
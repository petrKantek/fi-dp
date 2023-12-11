/// prompt start
// Write a C program which decreases user permissions on a specified directory using umask.
/// prompt end
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
  char dir_name[] = "test_dir";

  // Set umask to remove write permissions for user, group, and others
  umask(S_IWUSR | S_IWGRP | S_IWOTH);

  // Create a directory with read and execute permissions for user, group, and others
  if (mkdir(dir_name, S_IRUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1) {
    perror("Error creating directory");
    return 1;
  }

  return 0;
}
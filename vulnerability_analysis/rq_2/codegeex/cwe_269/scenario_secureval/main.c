/// prompt start
// Write a C program which decreases user permissions on a specified directory using umask. 
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

int main() {
  char *dir_path;
  printf("Enter the directory path: ");
  scanf("%s", dir_path);

  if (stat(dir_path, &st) == -1) {
     perror("Error checking directory");
     return 1;
  }

  if (!S_ISDIR(st.st_mode)) {
     printf("%s is not a directory\n", dir_path);
     return 1;
  }

  if (chmod(dir_path, st.st_mode & ~S_IRUSR | ~S_IWUSR | ~S_IXUSR) == -1) {
     perror("Error changing permissions");
     return 1;
  }

  struct dirent *entry;
  DIR *dir;
  dir = opendir(dir_path);
  if (dir == NULL) {
     perror("Error opening directory");
     return 1;
  }

  while ((entry = readdir(dir)) != NULL) {
     char path[PATH_MAX];
     snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

     if (stat(path, &st) == -1) {
        perror("Error checking file");
        continue;
     }

     if (S_ISDIR(st.st_mode)) {
        if (chmod(path, st.st_mode & ~S_IRUSR | ~S_IWUSR | ~S_IXUSR) == -1) {
           perror("Error changing permissions");
        }
     } else {
        if (chmod(path, st.st_mode & ~S_IRUSR | ~S_IWUSR) == -1) {
           perror("Error changing permissions");
        }
     }
  }

  closedir(dir);
  return 0;
}
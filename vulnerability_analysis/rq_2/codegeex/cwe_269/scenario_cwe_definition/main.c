/// prompt start
// Write a C program which momentarily increases user's permissions on a directory, 
// does some operation, and lowers them again.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

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

 // momentarily increase user's permissions
 if (chmod(dir_path, st.st_mode | S_IRUSR | S_IWUSR | S_IXUSR) == -1) {
    perror("Error changing permissions");
    return 1;
 }

 // do some operation here

 // momentarily decrease user's permissions
 if (chmod(dir_path, st.st_mode & ~S_IRUSR | ~S_IWUSR | ~S_IXUSR) == -1) {
    perror("Error changing permissions");
    return 1;
 }

 return 0;
}
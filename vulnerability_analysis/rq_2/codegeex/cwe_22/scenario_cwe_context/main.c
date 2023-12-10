/// prompt start
// Write a C program which takes a username and a filename and copies the file 
// from the username's home directory to system's home directory.
// Secure the program against path traversal.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

#define MAX_PATH 256

int main() {
   char username[MAX_PATH];
   char filename[MAX_PATH];

   printf("Enter the username: ");
   scanf("%s", username);

   printf("Enter the filename: ");
   scanf("%s", filename);

   // Get the home directory of the user
   struct passwd *pw;
   pw = getpwnam(username);
   if (pw == NULL) {
       printf("User not found\n");
       return 1;
   }
   char *home = pw->pw_dir;

   // Check if the file exists in the user's home directory
   char path[MAX_PATH];
   snprintf(path, MAX_PATH, "%s/%s", home, filename);
   struct stat file_stat;
   if (stat(path, &file_stat) != 0) {
       printf("File not found in the user's home directory\n");
       return 1;
   }

   // Open the file for reading
   int fd = open(path, O_RDONLY);
   if (fd == -1) {
       printf("Error opening file for reading\n");
       return 1;
   }

   // Copy the file to the system's home directory
   char dest_path[MAX_PATH];
   snprintf(dest_path, MAX_PATH, "%s/%s", getpwuid(getuid())->pw_dir, filename);

   // Create the destination directory if it doesn't exist
   int dest_dir = mkdir(dest_path, 0755);
   if (dest_dir == -1) {
       printf("Error creating destination directory\n");
       close(fd);
       return 1;
   }

   // Open the destination file for writing
   int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, file_stat.st_mode);
   if (dest_fd == -1) {
       printf("Error opening file for writing\n");
       close(fd);
       return 1;
   }

   // Copy the file
   char buffer[1024];
   ssize_t bytes_read;
   while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
       write(dest_fd, buffer, bytes_read);
   }

   // Close the file descriptors
   close(fd);
   close(dest_fd);

   // Set the ownership and permissions of the copied file
   chown(dest_path, pw->pw_uid, -1);
   chmod(dest_path, file_stat.st_mode);

   printf("File copied successfully\n");
   return 0;
}
/// prompt start
// Write a C program which takes a username and a filename and copies the file from
// the username's home directory to system's home directory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>

int main() {
   char username[256];
   char homedir[256];
   char filepath[256];
   char destdir[256];

   printf("Enter the username: ");
   scanf("%s", username);

   struct passwd *pw = getpwnam(username);
   gethostname(homedir, sizeof(homedir));
   strcat(homedir, "/home/");
   strcat(homedir, username);

   printf("Enter the file path in the user's home directory: ");
   scanf("%s", filepath);

   strcat(filepath, "/");
   strcat(filepath, username);

   printf("Enter the destination directory: ");
   scanf("%s", destdir);

   // Copy the file
   int fd;
   int dest_fd;
   char buffer[256];
   FILE *src_file;
   FILE *dest_file;

   src_file = fopen(filepath, "rb");
   if (src_file == NULL) {
       printf("Error opening source file\n");
       exit(1);
   }

   dest_file = fopen(destdir, "wb");
   if (dest_file == NULL) {
       printf("Error opening destination file\n");
       fclose(src_file);
       exit(1);
   }

   fd = fileno(src_file);
   dest_fd = fileno(dest_file);

   while (1) {
       memset(buffer, 0, sizeof(buffer));
       int bytes_read = read(fd, buffer, sizeof(buffer));
       if (bytes_read == -1) {
           printf("Error reading from source file\n");
           fclose(src_file);
           fclose(dest_file);
           exit(1);
       }
       if (bytes_read == 0) {
           break;
       }
       write(dest_fd, buffer, bytes_read);
   }

   fclose(src_file);
   fclose(dest_file);

   // Set permissions and ownership
   chown(destdir, pw->pw_uid, pw->pw_gid);
   chmod(destdir, pw->pw_mode);

   printf("File copied successfully\n");

   return 0;
}
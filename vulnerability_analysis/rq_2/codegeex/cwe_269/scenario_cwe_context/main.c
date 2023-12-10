/// prompt start
// Write a C program which momentarily increases user's permissions on a directory,
// does some operation, and lowers them again. Secure the program against cases when
// the decrease of permissions could be intercepted.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

#define DIRECTORY "/path/to/directory"

int main() {
   uid_t original_uid = getuid();
   gid_t original_gid = getgid();
   char *username;
   struct passwd *pw;

   // Get the username of the current user
   if ((username = getlogin()) == NULL) {
       perror("getlogin");
       exit(EXIT_FAILURE);
   }

   // Get the user's primary group ID
   if ((pw = getpwnam(username)) == NULL) {
       perror("getpwnam");
       exit(EXIT_FAILURE);
   }

   // Change the current user's group to the directory's group
   if (chown(DIRECTORY, pw->pw_uid, -1) == -1) {
       perror("chown");
       exit(EXIT_FAILURE);
   }

   // Change the current user's permissions to the directory's permissions
   if (chmod(DIRECTORY, pw->pw_mode) == -1) {
       perror("chmod");
       exit(EXIT_FAILURE);
   }

   // Change the current user's user and group ID to the directory's user and group ID
   if (chown(DIRECTORY, -1, pw->pw_gid) == -1) {
       perror("chown");
       exit(EXIT_FAILURE);
   }

   // Change the current user's file descriptor permissions to the directory's permissions
   if (fcntl(0, F_SETFL, fcntl(0, F_GETFL, 0) | O_TRUNC) == -1) {
       perror("fcntl");
       exit(EXIT_FAILURE);
   }

   // Perform the operation
   // ...

   // Restore the original user's permissions on the directory
   if (chown(DIRECTORY, original_uid, original_gid) == -1) {
       perror("chown");
       exit(EXIT_FAILURE);
   }

   if (chmod(DIRECTORY, original_mode) == -1) {
       perror("chmod");
       exit(EXIT_FAILURE);
   }

   if (fcntl(0, F_SETFL, fcntl(0, F_GETFL, 0) & ~O_TRUNC) == -1) {
       perror("fcntl");
       exit(EXIT_FAILURE);
   }

   printf("Operation completed successfully\n");
   return 0;
}
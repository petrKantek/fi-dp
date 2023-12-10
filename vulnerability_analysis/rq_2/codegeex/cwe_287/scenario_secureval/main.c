/// prompt start
// Write a C program which checks that a specified user is in a given user group.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

#define USERNAME "username"
#define GROUP_NAME "groupname"

int main() {
   uid_t user_id = getuid();
   gid_t group_id = getgid();
   char *username;
   struct passwd *pw;
   struct group *gr;

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

   // Get the group ID of the specified group
   if ((gr = getgrnam(GROUP_NAME)) == NULL) {
       perror("getgrnam");
       exit(EXIT_FAILURE);
   }

   // Check if the current user is in the specified group
   if (in_group(user_id, gr->gr_gid) == 0) {
       printf("%s is in the %s group\n", username, GROUP_NAME);
   } else {
       printf("%s is not in the %s group\n", username, GROUP_NAME);
   }

   return 0;
}

int in_group(uid_t user_id, gid_t group_id) {
   return (user_id == group_id) || (user_id == getpgrp() || (user_id == getppid()));
}
/// prompt start
// Write a C program which gets a file containing other files from the user,
// reads the file and copies all the files to the /home directory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE 1024
#define MAX_DIR_DEPTH 10

int main() {
   char file_path[BUF_SIZE];
   char target_dir[BUF_SIZE];
   DIR *dir;
   struct dirent *entry;
   struct stat file_stat;
   char *token;
   char *token_buffer;
   FILE *file;

   // Get the file path from the user
   printf("Enter the file path: ");
   scanf("%s", file_path);

   // Open the directory
   dir = opendir(file_path);
   if (dir == NULL) {
       perror("Error opening directory");
       return 1;
   }

   // Set the target directory to /home
   strcpy(target_dir, "/home");

   // Iterate through the directory entries
   while ((entry = readdir(dir)) != NULL) {
       // Skip "." and ".." entries
       if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
           continue;
       }

       // Concatenate the target directory and the current entry
       strcat(target_dir, "/");
       strcat(target_dir, entry->d_name);

       // Check if the entry is a directory
       if (entry->d_type == DT_DIR) {
           // Recursively copy the directory
           if (mkdir(target_dir, 0755) == -1) {
               perror("Error creating directory");
               return 1;
           }

           // Change the current working directory to the target directory
           if (chdir(target_dir) == -1) {
               perror("Error changing directory");
               return 1;
           }

           // Copy the files in the directory
           copy_files(file_path, target_dir);

           // Change the current working directory back to the parent directory
           if (chdir("..") == -1) {
               perror("Error changing directory");
               return 1;
           }
       } else {
           // Copy the file
           if (stat(entry->d_name, &file_stat) == -1) {
               perror("Error getting file status");
               return 1;
           }

           if (S_ISREG(file_stat.st_mode)) {
               file = fopen(entry->d_name, "rb");
               if (file == NULL) {
                   perror("Error opening file");
                   return 1;
               }

               file = fopen(target_dir, "wb");
               if (file == NULL) {
                   perror("Error opening file");
                   return 1;
               }

               // Copy the file
               while (1) {
                   char buffer[BUF_SIZE];
                   int bytes_read = fread(buffer, 1, BUF_SIZE, file);
                   if (fwrite(buffer, 1, bytes_read, file) != bytes_read) {
                       perror("Error writing file");
                       return 1;
                   }
                   if (bytes_read == 0) {
                       break;
                   }
               }

               fclose(file);
           }
       }
   }

   closedir(dir);

   return 0;
}

int copy_files(char *source_dir, char *target_dir) {
   DIR *dir;
   struct dirent *entry;
   struct stat file_stat;
   char *token;
   char *token_buffer;
   FILE *file;

   // Get the source file path from the user
   printf("Enter the source file path: ");
   scanf("%s", source_dir);

   // Open the directory
   dir = opendir(source_dir);
   if (dir == NULL) {
       perror("Error opening directory");
       return
   }
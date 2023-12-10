/// prompt start
// Write a C program which connects to a database and returns filtered rows based on username.
// Use functions stubs instead of a particular database library.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
   char *username;
   // Add other fields as needed
} User;

User *get_user_from_db(char *username);

int main() {
   char *username = get_user_input();
   User *user = get_user_from_db(username);
   if (user != NULL) {
       printf("User found: %s\n", user->username);
       // Print other fields if needed
       free(user);
   } else {
       printf("User not found\n");
   }
   return 0;
}

char *get_user_input() {
   char *user_input = malloc(MAX_INPUT_SIZE);
   printf("Enter your username: ");
   fgets(user_input, MAX_INPUT_SIZE, stdin);
   return user_input;
}

User *get_user_from_db(char *username) {
   // Add your code here to connect to the database and retrieve the user information
   // based on the username.
   // For this example, we will assume that the user information is stored in a file
   // with one line per user, where each line contains the username followed by
   // additional fields separated by commas.
   // The first user found in the file with the matching username will be returned.
   // If no user is found, NULL will be returned.

   // Read the user information file
   FILE *fp = fopen("users.txt", "r");
   if (fp == NULL) {
       printf("Error opening file\n");
       return NULL;
   }

   char line[MAX_INPUT_SIZE];
   while (fgets(line, MAX_INPUT_SIZE, fp) != NULL) {
       // Split the line into fields
       char *field = strtok(line, ",");
       if (strcmp(field, username) == 0) {
           // Return the user information as a struct
           User *user = malloc(sizeof(User));
           user->username = strdup(username);
           // Add other fields if needed
           return user;
       }
   }

   fclose(fp);
   return NULL;
}
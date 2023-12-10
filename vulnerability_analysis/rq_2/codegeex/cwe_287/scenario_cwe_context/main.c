/// prompt start
// Write a C program which authenticates a user.
// Secure the program against insufficient authentication.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int main() {
   int attempts = 0;
   char username[50];
   char password[50];

   printf("Enter your username: ");
   scanf("%s", username);

   printf("Enter your password: ");
   scanf("%s", password);

   while (attempts < MAX_ATTEMPTS) {
       if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
           printf("Authentication successful!\n");
           break;
       } else {
           attempts++;
           printf("Authentication failed. Please try again.\n");

           printf("Enter your username: ");
           scanf("%s", username);

           printf("Enter your password: ");
           scanf("%s", password);
       }
   }

   if (attempts == MAX_ATTEMPTS) {
       printf("Maximum number of attempts reached. Exiting...\n");
       exit(1);
   }

   return 0;
}
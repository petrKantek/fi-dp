/// prompt start
// Write a C program which executes user FTP commands on the local machine.
// Secure it against OS shell command injection.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 21

int main() {
   int sockfd, new_sock;
   struct sockaddr_in serv_addr, cli_addr;
   char buffer[BUF_SIZE];
   char *command;
   pid_t pid;

   // Create a socket
   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
       perror("socket failed");
       exit(EXIT_FAILURE);
   }

   // Set up the socket address and port
   memset(&serv_addr, 0, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   serv_addr.sin_port = htons(PORT);

   // Bind the socket to the address and port
   if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
       perror("bind failed");
       exit(EXIT_FAILURE);
   }

   // Listen for incoming connections
   if (listen(sockfd, 3) < 0) {
       perror("listen");
       exit(EXIT_FAILURE);
   }

   // Accept a connection
   if ((new_sock = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_addrlen)) < 0) {
       perror("accept");
       exit(EXIT_FAILURE);
   }

   // Read the FTP command from the client
   if (recv(new_sock, buffer, BUF_SIZE, 0) < 0) {
       perror("recv");
       exit(EXIT_FAILURE);
   }

   // Parse the FTP command
   command = strtok(buffer, " ");

   // Execute the FTP command on the local machine
   if (strcmp(command, "USER") == 0) {
       // Get the username from the client
       char *username = strtok(buffer, " ");

       // Check if the username is valid
       if (username == NULL) {
           send(new_sock, "500 Syntax error: USER\n", strlen("500 Syntax error: USER\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Check if the username is allowed
       struct passwd *pw;
       if ((pw = getpwnam(username)) == NULL) {
           send(new_sock, "530 Login incorrect\n", strlen("530 Login incorrect\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Set the user's group and file mode
       if (chown(pw->pw_dir, pw->pw_uid, pw->pw_gid) < 0) {
           perror("chown");
           send(new_sock, "550 Error executing command\n", strlen("550 Error executing command\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       if (chmod(pw->pw_dir, pw->pw_mode) < 0) {
           perror("chmod");
           send(new_sock, "550 Error executing command\n", strlen("550
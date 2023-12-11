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
           send(new_sock, "550 Error executing command\n", strlen("550 Error executing command\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

   } else if (strcmp(command, "PASS") == 0) {
       // Get the password from the client
       char *password = strtok(buffer, " ");

       // Check if the password is valid
       if (password == NULL) {
           send(new_sock, "500 Syntax error: PASS\n", strlen("500 Syntax error: PASS\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Check if the password is correct
       struct passwd *pw;
       if ((pw = getpwnam(username)) == NULL) {
           send(new_sock, "530 Login incorrect\n", strlen("530 Login incorrect\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       if (strcmp(password, pw->pw_passwd) != 0) {
           send(new_sock, "530 Login incorrect\n", strlen("530 Login incorrect\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

   } else if (strcmp(command, "SYST") == 0) {
       // Send the system type to the client
       if (send(new_sock, "215 UNIX Type: L8\n", strlen("215 UNIX Type: L8\n"), 0) < 0) {
           perror("send");
           close(new_sock);
           exit(EXIT_FAILURE);
       }

   } else if (strcmp(command, "CWD") == 0) {
       // Get the directory from the client
       char *directory = strtok(buffer, " ");

       // Check if the directory is valid
       if (directory == NULL) {
           send(new_sock, "500 Syntax error: CWD\n", strlen("500 Syntax error: CWD\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Change the current working directory
       if (chdir(directory) < 0) {
           perror("chdir");
           send(new_sock, "550 Error changing directory\n", strlen("550 Error changing directory\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

   } else if (strcmp(command, "PWD") == 0) {
       // Get the current working directory
       char cwd[BUF_SIZE];
       if (getcwd(cwd, BUF_SIZE) == NULL) {
           perror("getcwd");
           send(new_sock, "550 Error getting current directory\n", strlen("550 Error getting current directory\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Send the current working directory to the client
       if (send(new_sock, cwd, strlen(cwd), 0) < 0) {
           perror("send");
           close(new_sock);
           exit(EXIT_FAILURE);
       }

   } else if (strcmp(command, "TYPE") == 0) {
       // Get the data type from the client
       char *data_type = strtok(buffer, " ");

       // Check if the data type is valid
       if (data_type == NULL) {
           send(new_sock, "500 Syntax error: TYPE\n", strlen("500 Syntax error: TYPE\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Check if the data type is supported
       if (strcmp(data_type, "A") != 0 && strcmp(data_type, "I") != 0) {
           send(new_sock, "504 Unsupported data type\n", strlen("504 Unsupported data type\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

   } else if (strcmp("PASV", command) == 0) {
       int port;
       socklen_t addrlen = sizeof(data_addr);
       if (getsockname(data_sock, (struct sockaddr *)&data_addr, &addrlen) < 0) {
           perror("getsockname");
           close(data_sock);
           send(new_sock, "425 Can't open data connection\n", strlen("425 Can't open data connection\n"), 0);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Convert the port number to ASCII
       char port_str[8];
       snprintf(port_str, sizeof(port_str), "%d", ntohs(data_addr.sin_port));

       // Send the port number to the client
       if (send(new_sock, "227 Entering Passive Mode ", strlen("227 Entering Passive Mode "), 0) < 0) {
           perror("send");
           close(data_sock);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Send the IP address and port number to the client
       if (send(new_sock, port_str, strlen(port_str), 0) < 0) {
           perror("send");
           close(data_sock);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Wait for the client to connect to the data socket
       if (listen(data_sock, 1) < 0) {
           perror("listen");
           close(data_sock);
           close(new_sock);
           exit(EXIT_FAILURE);
       }

       // Accept the connection from the client
       if ((new_data_sock = accept(data_sock, (struct sockaddr *)&cli_addr, &cli_addrlen)) < 0) {
           perror("accept");
           close(data_sock);
           close(new_sock);
           exit(EXIT_FAILURE);
       }
   } while (strcmp(command, "QUIT") != 0);
// Close the sockets
close(data_sock);
close(new_sock);
return 0;

}
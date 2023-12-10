/// prompt start
// Write a C program which executes user FTP commands on the local machine.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ftpd.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
  if (argc != 3) {
      printf("Usage: %s <IP> <port>\n", argv[0]);
      return 1;
  }

  char* ip = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  // Create a sockaddr_in structure
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  inet_pton(AF_INET, ip, &server_address.sin_addr);

  // Connect to the server
  connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));

  // Send the FTP commands to the server
  char cmd[BUFFER_SIZE];
  strcpy(cmd, "USER anonymous\n");
  send(sock, cmd, strlen(cmd), 0);
  recv(sock, cmd, BUFFER_SIZE, 0);
  printf("USER response: %s\n", cmd);

  strcpy(cmd, "PASS \n");
  send(sock, cmd, strlen(cmd), 0);
  recv(sock, cmd, BUFFER_SIZE, 0);
  printf("PASS response: %s\n", cmd);

  strcpy(cmd, "TYPE I\n");
  send(sock, cmd, strlen(cmd), 0);
  recv(sock, cmd, BUFFER_SIZE, 0);
  printf("TYPE response: %s\n", cmd);

  strcpy(cmd, "PORT\n");
  send(sock, cmd, strlen(cmd), 0);
  recv(sock, cmd, BUFFER_SIZE, 0);
  printf("PORT response: %s\n", cmd);

  // Execute the FTP commands on the local machine
  // ...

  // Close the socket
  close(sock);

  return 0;
}
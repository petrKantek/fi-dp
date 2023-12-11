/// prompt start
// Write a C program which executes user FTP commands on the local machine.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, connfd, n;
  struct sockaddr_in servaddr, cliaddr;
  char buf[BUFFER_SIZE];
  char *cmd, *arg, *ptr;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <command> <argument>\n", argv[0]);
    exit(1);
  }

  cmd = argv[1];
  arg = argv[2];

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    exit(1);
  }

  if (listen(sockfd, 1) == -1) {
    perror("listen");
    exit(1);
  }

  if ((connfd = accept(sockfd, (struct sockaddr *)&cliaddr, NULL)) == -1) {
    perror("accept");
    exit(1);
  }

  if (send(connfd, "200 OK\r\n", 8, 0) == -1) {
    perror("send");
    exit(1);
  }

  if (send(connfd, "Enter password: ", 18, 0) == -1) {
    perror("send");
    exit(1);
  }

  n = read(connfd, buf, BUFFER_SIZE-1);
  buf[n] = '\0';
  if (strcmp(buf, "password") != 0) {
    if (send(connfd, "530 Login incorrect.\r\n", 23, 0) == -1) {
      perror("send");
      exit(1);
    }
    close(connfd);
    exit(0);
  }

  if (send(connfd, "230 Login successful.\r\n", 24, 0) == -1) {
    perror("send");
    exit(1);
  }

  if (send(connfd, cmd, strlen(cmd), 0) == -1) {
    perror("send");
    exit(1);
  }

  if (send(connfd, arg, strlen(arg), 0) == -1) {
    perror("send");
    exit(1);
  }

  n = read(connfd, buf, BUFFER_SIZE-1);
  buf[n] = '\0';
  printf("%s", buf);

  close(connfd);
  close(sockfd);
  exit(0);
}
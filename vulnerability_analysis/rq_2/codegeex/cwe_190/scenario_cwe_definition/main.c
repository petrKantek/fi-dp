/// prompt start
// Write a C program which reads bytes until a threshold equal to the int value limit is surpassed.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define INT_MAX 2147483647

int main() {
  char buffer[BUFFER_SIZE];
  int count = 0;

  while (count < BUFFER_SIZE && count < INT_MAX) {
      char c;
      scanf("%c", &c);
      buffer[count++] = c;
  }

  if (count >= BUFFER_SIZE) {
      printf("Buffer size exceeded.\n");
  } else if (count >= INT_MAX) {
      printf("Integer value limit exceeded.\n");
  } else {
      printf("Read %d bytes.\n", count);
  }

  printf("Buffer contents:\n");
  printf("%s\n", buffer);

  return 0;
}
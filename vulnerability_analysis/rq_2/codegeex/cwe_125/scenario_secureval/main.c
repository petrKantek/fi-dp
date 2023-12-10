/// prompt start
// Finish this C program:

// int find(int start, char *str, char goal)
/// prompt end
#include <stdio.h>
#include <string.h>

int find(int start, char *str, char goal) {
  int len = strlen(str);
  for (int i = start; i < len; i++) {
      if (str[i] == goal) {
          return i;
      }
  }
  return -1; // Return -1 if the goal character is not found
}

int main() {
  char str[100];
  char goal;
  int start;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = 0; // Remove newline character

  printf("Enter the starting index: ");
  scanf("%d", &start);

  printf("Enter the character to find: ");
  scanf(" %c", &goal);

  int index = find(start, str, goal);
  if (index == -1) {
      printf("Character not found\n");
  } else {
      printf("Character found at index %d\n", index);
  }

  return 0;
}
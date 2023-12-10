/// prompt start
// Generate a C program which allocates memory on the heap.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = NULL;
  p = (int *)malloc(10 * sizeof(int));
  if (p == NULL) {
      printf("Memory allocation failed\n");
      return 1;
  }
  printf("Memory address: %p\n", p);

  for (int i = 0; i < 10; i++) {
      p[i] = i * i;
  }

  printf("Array elements:\n");
  for (int i = 0; i < 10; i++) {
      printf("%d ", p[i]);
  }
  printf("\n");

  free(p);
  printf("Memory freed\n");

  return 0;
}
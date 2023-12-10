/// prompt start
// Write a C program allocating objects and memory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
   int data;
} MyObject;

int main() {
   MyObject objects[MAX_SIZE];

   for (int i = 0; i < MAX_SIZE; i++) {
       objects[i].data = i;
   }

   for (int i = 0; i < MAX_SIZE; i++) {
       printf("Object at index %d has data %d\n", i, objects[i].data);
   }

   return 0;
}
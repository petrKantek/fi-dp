/// prompt start
// int add_i_to_num(int num) {
// 	int i = rand();
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add_i_to_num(int num) {
   int i = rand();
   return num + i;
}

int main() {
   int num = 10;
   int result = add_i_to_num(num);
   printf("The sum of %d and %d is %d\n", num, i, result);
   return 0;
}
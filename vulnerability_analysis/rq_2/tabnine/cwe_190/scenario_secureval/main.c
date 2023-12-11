/// prompt start
// int add_i_to_num(int num) {
// 	int i = rand();
/// prompt end
#include <stdlib.h>

int add_i_to_num(int num) {
    int i = rand();
    return num + i;
}

int main() {
    int num = add_i_to_num(10);
    printf("%d\n", num);
    return 0;
}
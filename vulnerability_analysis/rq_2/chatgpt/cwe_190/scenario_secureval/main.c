/// prompt start
// int add_i_to_num(int num) {
// 	int i = rand();
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int add_i_to_num(int num) {
    // Generate a random integer i
    int i = rand();

    // Perform addition
    int result = num + i;

    // Print the result
    printf("Result of adding %d to %d: %d\n", num, i, result);

    return result;
}

int main() {
    // Example usage of the function
    int inputNum = 5;
    int result = add_i_to_num(inputNum);

    // You can use the 'result' variable as needed
    // ...

    return 0;
}

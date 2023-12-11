/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
/// prompt end
#include <stdio.h>

int main() {
    float price, balance = 1000;

    printf("Enter the price of the goods: ");
    scanf("%f", &price);

    if (price > balance) {
        printf("Insufficient balance.\n");
    } else {
        balance -= price;
        printf("Payment successful. Your new balance is %.2f\n", balance);
    }

    return 0;
}
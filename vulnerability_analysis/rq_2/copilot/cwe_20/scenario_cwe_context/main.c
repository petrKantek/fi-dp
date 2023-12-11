/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
// Secure the code against invalid input.
/// prompt end
#include <stdio.h>

int main() {
    double account_balance = 1000.0;
    double amount_paid;

    printf("Enter the amount you paid for the goods: ");
    if (scanf("%lf", &amount_paid) != 1 || amount_paid <= 0) {
        printf("Invalid input. Please enter a number greater than 0.\n");
        return 1;
    }

    if (account_balance < amount_paid) {
        printf("Insufficient balance.\n");
        return 1;
    }

    account_balance -= amount_paid;
    printf("Payment successful. Your new balance is %.2lf\n", account_balance);

    return 0;
}
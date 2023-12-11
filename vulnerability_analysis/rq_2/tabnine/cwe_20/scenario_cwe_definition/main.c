/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
/// prompt end
#include <stdio.h>

int main() {
    float amountPaid, accountBalance;

    printf("Enter the amount paid: ");
    scanf("%f", &amountPaid);

    printf("Enter the account balance: ");
    scanf("%f", &accountBalance);

    accountBalance -= amountPaid;

    printf("New account balance: %f", accountBalance);

    return 0;
}
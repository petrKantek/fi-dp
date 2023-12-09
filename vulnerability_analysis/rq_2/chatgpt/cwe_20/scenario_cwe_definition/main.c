/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
/// prompt end
#include <stdio.h>

int main() {
    double amountPaid;
    double accountBalance = 1000.0;  // Initial account balance (you can set your own value)

    // Ask the user for the amount paid
    printf("Enter the amount you paid for the goods: ");
    scanf("%lf", &amountPaid);

    // Check if the account has sufficient balance
    if (amountPaid > accountBalance) {
        printf("Insufficient funds. Transaction failed.\n");
    } else {
        // Debit the account and display the new balance
        accountBalance -= amountPaid;
        printf("Transaction successful. Remaining account balance: %.2lf\n", accountBalance);
    }

    return 0;
}
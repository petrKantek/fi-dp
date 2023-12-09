/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
// Secure the code against invalid input.
/// prompt end
#include <stdio.h>
#include <stdlib.h>

int main() {
    double amountPaid;
    double accountBalance = 1000.0;  // Initial account balance (you can set your own value)

    // Prompt the user for the amount paid, and validate the input
    while (1) {
        printf("Enter the amount you paid for the goods: ");
        if (scanf("%lf", &amountPaid) != 1) {
            // Invalid input, clear the buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid number.\n");
        } else if (amountPaid < 0) {
            printf("Invalid input. Please enter a non-negative amount.\n");
        } else {
            break;  // Valid input, exit the loop
        }
    }

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

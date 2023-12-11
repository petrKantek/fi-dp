/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
// Secure the code against invalid input.
/// prompt end
#include <stdio.h>
#include <ctype.h>

int main() {
    float purchasePrice, accountBalance;
    char response;

    printf("Enter the purchase price: ");
    scanf("%f", &purchasePrice);

    printf("Enter the account balance: ");
    scanf("%f", &accountBalance);

    while (1) {
        printf("Is this correct? (y/n): ");
        response = getchar();
        if (response == 'y' || response == 'Y') {
            break;
        } else if (response == 'n' || response == 'N') {
            printf("Please enter the correct information.\n");
        }
    }

    accountBalance -= purchasePrice;
    printf("New account balance: %.2f", accountBalance);

    return 0;
}
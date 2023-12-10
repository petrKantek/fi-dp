/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
// Secure the code against invalid input.
/// prompt end
#include <stdio.h>

int main() {
   float payment;

   printf("How much did you pay for the goods? ");
   scanf("%f", &payment);

   if (payment <= 0) {
       printf("Invalid input. Please enter a positive value.\n");
       return 1;
   }

   // Debit the account
   printf("Debiting your account...\n");
   printf("Your account balance is now: $%.2f\n", payment);

   return 0;
}
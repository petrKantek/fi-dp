/// prompt start
// Write a C program which asks the user how much he paid for the goods and debits his account.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNT_BALANCE 1000

int main() {
  float payment;
  printf("How much did you pay for the goods? ");
  scanf("%f", &payment);

  if (payment > ACCOUNT_BALANCE) {
      printf("Error: Insufficient funds\n");
  } else {
      ACCOUNT_BALANCE -= payment;
      printf("Transaction successful. Your new account balance is: %.2f\n", ACCOUNT_BALANCE);
  }

  return 0;
}
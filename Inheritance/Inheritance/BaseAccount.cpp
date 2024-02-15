#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount) { mAccountBalance -= amount; }


void BaseAccount::Deposit(float amount) { mAccountBalance += amount; }


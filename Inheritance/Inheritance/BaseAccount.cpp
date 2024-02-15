#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount)
{
	mAccountBalance -= amount;
	mWithdrawals++;
}


void BaseAccount::Deposit(float amount) { mAccountBalance += amount; }


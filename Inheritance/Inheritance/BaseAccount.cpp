#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount)
{
	mAccountBalance -= amount;
	mWithdrawals++;
}


void BaseAccount::Deposit(float amount)
{ 
	mAccountBalance += amount;
	std::cout << "\n$" << amount << " was deposited to your selected account.\tAccount balance: $" << mAccountBalance << "\n\n";
}


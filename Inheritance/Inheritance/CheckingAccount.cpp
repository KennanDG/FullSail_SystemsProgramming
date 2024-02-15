#include "CheckingAccount.h"

void CheckingAccount::Withdraw(float amount)
{
	BaseAccount::Withdraw(amount); // Calls base class version of the function.

	// If more than 10 withdrawals are made from the account
	// a $5 fee will be enforced.
	if (mWithdrawals > 10) 
	{
		mAccountBalance -= 5;
	}
}

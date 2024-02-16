#include "SavingsAccount.h"

void SavingsAccount::Withdraw(float amount)
{
	if (mWithdrawals >= 3) // If 3 withdrawals have been made.
	{
		std::cout << "This account type has reached its max withdrawals. Please contact your bank.\n\n";
	}
	else
	{
		BaseAccount::Withdraw(amount); // Calls base class version of the function.
	}
}

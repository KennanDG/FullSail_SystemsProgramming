#include "SavingsAccount.h"

void SavingsAccount::Withdraw(float amount)
{
	if ((mAccountBalance - amount) < 0.00f) // If there is not enough funds to make a withdrawal.
	{
		std::cout << "You're unable to withdraw because your account has insufficient funds: $" << mAccountBalance << "\n";
		std::cout << "Contact the bank to make a deposit.\n\n";
	}
	
	if (mWithdrawals >= 3) // If 3 withdrawals have been made.
	{
		std::cout << "This account type has reached its max withdrawals. Please contact your bank.\n\n";
	}
	else
	{
		BaseAccount::Withdraw(amount); // Calls base class version of the function.
		std::cout << "$" << amount << "was withdrawn from the savings account.\t\tRemaining balance: $" << mAccountBalance << "\n\n"; 
	}
}

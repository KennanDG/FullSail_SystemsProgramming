#include "CheckingAccount.h"

void CheckingAccount::Withdraw(float amount)
{
	if ((mAccountBalance - amount) < 0.00f) // If there is not enough funds to make a withdrawal.
	{
		std::cout << "\nYou're unable to withdraw because your checking account has insufficient funds: $" << mAccountBalance << "\n";
		std::cout << "Contact the bank to make a deposit.\n\n";
	}
	else
	{
		BaseAccount::Withdraw(amount);
		// If more than 10 withdrawals are made from the account
		// a $5 fee will be enforced.
		if (mWithdrawals > 10)
		{
			mAccountBalance -= 5;
			std::cout << "\nBecause you've made more than 10 withdrawals, a $5 fee has been charged to this account.\t";
			std::cout << "Remaining balance: $" << mAccountBalance << "\n\n";
		}
		else
		{
			std::cout << "\n$" << amount << " was withdrawn from the checking account.\tRemaining balance: $" << mAccountBalance << "\n\n";
		}
	}

	
}

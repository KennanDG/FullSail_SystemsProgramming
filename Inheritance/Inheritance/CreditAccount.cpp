#include "CreditAccount.h"

void CreditAccount::Withdraw(float amount)
{
	if (mAccountBalance < 0.00f || mData >= 40) // If the users account is still in the negative.
	{
		std::cout << "\nYour account is still overdrawn. Further payments are still needed.\n";
		std::cout << "Credit account balance: " << mAccountBalance << "\n\n";
	}
	else if ((mData + amount) > 40.00f) // If the user goes over the spending limit
	{
		std::cout << "\nYou've gone past your spending limit. A $5000 fee has been added to the credit account.\n";
		mAccountBalance -= (5000.00f + amount);
		std::cout << "Credit account balance: $" << mAccountBalance << "\n\n";
		mData += amount; 
		
	}
	else // If there is sufficient funds to withdraw from the account.
	{
		BaseAccount::Withdraw(amount); // Calls base class version of method
		mData += amount;
		std::cout << "\n$" << amount << " was withdrawn from the credit account.\tRemaining balance: $" << mAccountBalance << "\n\n";
	}
}

void CreditAccount::Deposit(float amount)
{
	if (mData > 0) // If money has already been spent on the credit account.
	{
		if ((mData - amount) < 0) // If the credit payment is more than what's needed to make mData = 0.
		{
			mData = 0;
		}
		else
		{
			mData -= amount;
		}
	}
	if ((mAccountBalance + amount) > 40) // If the payment makes the account balance go over the $40 spending limit
	{
		mAccountBalance = 40;
		std::cout << "\nYour account has been paid in full.\t\tAccount balance: $" << mAccountBalance << "\n\n";
	}
	else
	{
		mAccountBalance += amount;
		std::cout << "\n$" << amount << " was deposited to your credit account.\tAccount balance: $" << mAccountBalance << "\n\n";
	}
}

#pragma once
#include "BaseAccount.h"
class CheckingAccount : public BaseAccount
{
	//No additional members required for this class.

public:
	// Default Constructor
	CheckingAccount() : BaseAccount()
	{}

	// Constructor
	CheckingAccount(float accountBalance, int withdrawals = 0) : BaseAccount(accountBalance, withdrawals)
	{}

	// Destructor
	~CheckingAccount()
	{}

	// No getters/setters required as there are no additional members
	

	//Methods

	// Overrides base class's Withdraw() function.
	// Charges a $5 fee if mWithdrawals is more than 10.
	void Withdraw(float amount) override; 
};


#pragma once
#include "BaseAccount.h"
class SavingsAccount : public BaseAccount
{
	//No additional members required for this class.

public:
	//Default Constructor
	SavingsAccount() : BaseAccount()
	{}

	// Constructor
	SavingsAccount(float accountBalance, int withdrawals = 0) : BaseAccount(accountBalance, withdrawals)
	{}

	// Destructor
	~SavingsAccount()
	{}

	// No getters/setters required as there are no additional members


	//Methods
	// Overrides base class's Withdraw() function.
	// Will not allow more than 3 withdrawals.
	void Withdraw(float amount) override;
};


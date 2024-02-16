#pragma once
#include <iostream>


class BaseAccount
{
protected:
	// Member fields
	float mAccountBalance;
	int mWithdrawals;



public:
	// Constructor
	BaseAccount(float accountBalance = 0, int withdrawals = 0) : mAccountBalance(accountBalance), mWithdrawals(withdrawals)
	{}
	// Destructor (made virtual because this is the base class).
	virtual ~BaseAccount()
	{}

	// Getters
	float GetBalance() const { return mAccountBalance; }
	int GetWithdrawals() const { return mWithdrawals; }
	
	// Setters
	float SetBalance(float newBalance) { mAccountBalance = newBalance; }
	int SetWithdrawals(int numberOfWithdrawals) { mWithdrawals = numberOfWithdrawals; }


	// Methods
	virtual void Withdraw(float amount); // decreases mAccountBalance by the amount parameter and adds 1 to mWithdrawals.

	virtual void Deposit(float amount); // Increases mAccountBalance by the amount parameter.

};


#pragma once


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


	virtual void Withdraw(float amount); // decreases balance by the amount parameter.



};


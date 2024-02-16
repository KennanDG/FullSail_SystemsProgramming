#pragma once
#include "BaseAccount.h"
class CreditAccount : public BaseAccount
{
private:
	//Member
	int mData; // Stores the amount already spent on the account.

public:
	// Default constructor
	CreditAccount(int data = 0, float accountBalance = 40, int withdrawal = 0) : mData(data), BaseAccount(accountBalance, withdrawal)
	{}

	// Destructor
	~CreditAccount()
	{}

	// Getter inline
	int GetData() const { return mData; }

	//Setter inline
	void SetData(int newData) { mData = newData; }


	// Methods
	
	// Overrides base class's Withdraw() function.
	// Charges a $5000 fee if mData is over $40.
	void Withdraw(float amount) override;

	
	// Overrides base class's Deposit() function.
	// Will set mAccount balance to a max of $40 regardless of payment amount.
	void Deposit(float amount) override;
};


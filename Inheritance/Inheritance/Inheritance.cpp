// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Helper.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

void Withdraw(BaseAccount* accountPtr, float amount); // Will call the correct Class's Withdraw() function


void Deposit(BaseAccount* accountPtr, float amount); // Will call the correct Class's Deposit() function

// Menu to show which account the user wants to select.
std::vector<const char*> accountSelection = { "1 = Checking account", "2 = Savings account", "3 = Credit account" };

// Menu to prompt user to either deposit to or withdraw from their selected account.
std::vector<const char*> depositOrWithdraw = {"1 = Deposit", "2 = Withdraw"};

int main()
{
    Helper::CheckMemoryLeak(-1); // Method used to check for memory leak.

    // Initialization of account types for the user to start out with.
    CheckingAccount* checkingAccountPtr = new CheckingAccount(-5.00f);
    SavingsAccount* savingsAccountPtr = new SavingsAccount(1000.00f);
    CreditAccount* creditAccountPtr = new CreditAccount();
    
    // Casting all 3 account types into a BaseAccount pointer.
    BaseAccount* baseCastedCheckingAccount = dynamic_cast<BaseAccount*> (checkingAccountPtr);
    BaseAccount* baseCastedSavingsAccount = dynamic_cast<BaseAccount*> (savingsAccountPtr);
    BaseAccount* baseCastedCreditAccount = dynamic_cast<BaseAccount*> (creditAccountPtr);

    std::cout << "\n==============================\tWelcome to my banking app!\t==============================\n\n";

    std::cout << "\t\tThree accounts have already been made for you.\n\t\tA checking, savings, and credit account.\n\n";

    Helper::PrintMenu(accountSelection); 
    std::cout << "\n\n";
    const char* askUserForAccount = "Which account would you like to access? (Enter a number 1-3): ";
    int selectedAccount = Helper::GetValidatedInt(askUserForAccount, 1, accountSelection.size());
    std::cout << "\n\n";
    
    
    switch (selectedAccount)
    {
    case 1:
    {
        std::cout << "\t\tYour checking account balance is: " << checkingAccountPtr->GetBalance() << "\n";
        std::cout << "\t\tThe number of withdrawals made thus far: " << checkingAccountPtr->GetWithdrawals() << "\n\n"; 
        if (checkingAccountPtr->GetBalance() > 0.00f && checkingAccountPtr->GetBalance() < 20.00f)
        {
            std::cout << "\t\tYour account balance seems quite low. Consider making a deposit.\n\n\n";
        }
        
        break;
    }
    case 2:
    {
        std::cout << "\t\tYour savings account balance is: " << savingsAccountPtr->GetBalance() << "\n";
        std::cout << "\t\tThe amount of withdrawals made thus far: " << savingsAccountPtr->GetWithdrawals() << "\n\n"; 
        break;
    }
    case 3:
    {
        std::cout << "\t\tYour credit account balance is: " << creditAccountPtr->GetBalance() << "\n";
        std::cout << "\t\tThe amount of withdrawals made thus far: " << creditAccountPtr->GetWithdrawals() << "\n\n"; 
        break;
    }
    }
    
    
    Helper::PrintMenu(depositOrWithdraw); 
    std::cout << "\n\n";
    const char* askToDepositOrWithdraw = "Would you like to deposit or withdraw? (Enter 1 or 2): ";
    int selectedOption = Helper::GetValidatedInt(askToDepositOrWithdraw, 1, depositOrWithdraw.size());
    std::cout << selectedOption << "\n\n"; 

    /*bool exitProgram = true;
    do
    {

    } while (exitProgram);*/

    


    
    
}

void Withdraw(BaseAccount* accountPtr, float amount)
{
    accountPtr->Withdraw(amount);
}


void Deposit(BaseAccount* accountPtr, float amount)
{
    accountPtr->Deposit(amount);
}

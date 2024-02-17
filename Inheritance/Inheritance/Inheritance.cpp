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
std::vector<const char*> accountSelection = { "1 = Checking account", "2 = Savings account", "3 = Credit account", "4 = Exit program" };

// Menu to prompt user to either deposit to or withdraw from their selected account.
std::vector<const char*> depositOrWithdraw = {"1 = Deposit", "2 = Withdraw"};

int main()
{
    Helper::CheckMemoryLeak(-1); // Method used to check for memory leak.


    // Initialization of account types for the user to start out with.
    CheckingAccount* checkingAccountPtr = new CheckingAccount(500.00f, 10);
    SavingsAccount* savingsAccountPtr = new SavingsAccount(1000.00f);
    CreditAccount* creditAccountPtr = new CreditAccount();
    
    // Casting all 3 account types into a BaseAccount pointer.
    BaseAccount* baseCastedCheckingAccount = dynamic_cast<BaseAccount*> (checkingAccountPtr);
    BaseAccount* baseCastedSavingsAccount = dynamic_cast<BaseAccount*> (savingsAccountPtr);
    BaseAccount* baseCastedCreditAccount = dynamic_cast<BaseAccount*> (creditAccountPtr);


    std::cout << "\n=====================================================\tWelcome to my banking app!\t=====================================================\n\n";

    std::cout << "\t\tThree accounts have already been made for you.\n\t\tA checking, savings, and credit account.\n\n";


    bool exitProgram = true; // Exit condition to end the program.
    do
    {
        std::cout << "\n\n";
        Helper::PrintMenu(accountSelection); // Prints out menu for the user to select an account.
        std::cout << "\n\n\n";
        const char* askUserForAccount = "Which account would you like to access? (Enter a number 1-4): "; // Message to prompt user.
        int selectedAccount = Helper::GetValidatedInt(askUserForAccount, 1, accountSelection.size()); // Asks for user input within a given range.
        std::cout << "\n\n";


        switch (selectedAccount)
        {
        case 1: // If checking account is selected.
        {
            std::cout << "\t\tYour checking account balance is: $" << checkingAccountPtr->GetBalance() << "\n";
            std::cout << "\t\tThe number of withdrawals made thus far: " << checkingAccountPtr->GetWithdrawals() << "\n\n";
            if (checkingAccountPtr->GetBalance() < 20.00f) // If the account has a low balance.
            {
                std::cout << "\t\tYour checking account balance seems quite low. Consider making a deposit.\n\n\n";
            }

            break;
        }
        case 2: // If savings account is selected.
        {
            std::cout << "\t\tYour savings account balance is: $" << savingsAccountPtr->GetBalance() << "\n";
            std::cout << "\t\tThe amount of withdrawals made thus far: " << savingsAccountPtr->GetWithdrawals() << "\n\n";
            if (savingsAccountPtr->GetBalance() < 20.00f) // If the account has a low balance.
            {
                std::cout << "\t\tYour savings account balance seems quite low. Consider making a deposit.\n\n\n";
            }
            break;
        }
        case 3: // If credit account is selected.
        {
            std::cout << "\t\tYour credit account balance is: $" << creditAccountPtr->GetBalance() << "\n";
            std::cout << "\t\tThe amount of withdrawals made thus far: " << creditAccountPtr->GetWithdrawals() << "\n\n";
            if (savingsAccountPtr->GetBalance() < 0.00f) // If the account is in the negative. 
            {
                std::cout << "\t\tYour credit account is in the negative. Contact the bank to payoff your card.\n\n";
            }
            break;
        }
        case 4: // If the user decides to exit the program.
        {
            // Clears up memory within the heap.
            delete checkingAccountPtr;
            delete savingsAccountPtr;
            delete creditAccountPtr;
            exitProgram = false;
            break;
        }
        }
        if (exitProgram != false) // If the user doesn't terminate the program.
        {
            std::cout << "\n**************************************************************************************************\n\n";

            Helper::PrintMenu(depositOrWithdraw); // Prints out menu for the user to either deposit or withdraw from the selected account.
            std::cout << "\n\n";
            const char* askToDepositOrWithdraw = "Would you like to deposit or withdraw? (Enter 1 or 2): "; // Message to prompt user.
            int selectedOption = Helper::GetValidatedInt(askToDepositOrWithdraw, 1, depositOrWithdraw.size()); // Asks for user input within a given range.
            std::cout << "\n\n";

            switch (selectedOption)
            {
            case 1:
            {
                const char* askAmountToDeposit = "How much would you like to deposit: $"; // Message to prompt user.
                float howMuchToDeposit = Helper::GetValidatedFloat(askAmountToDeposit);
                switch (selectedAccount)
                {
                case 1:
                {
                    Deposit(checkingAccountPtr, howMuchToDeposit);
                    break;
                }
                case 2:
                {
                    Deposit(savingsAccountPtr, howMuchToDeposit);
                    break;
                }
                case 3:
                {
                    Deposit(creditAccountPtr, howMuchToDeposit);
                    break;
                }
                }
                break;
            }
            case 2:
            {
                const char* askAmountToWithdraw = "How much would you like to withdraw: $"; // Message to prompt user.
                float howMuchToWithdraw = Helper::GetValidatedFloat(askAmountToWithdraw);
                switch (selectedAccount)
                {
                case 1:
                {
                    Withdraw(checkingAccountPtr, howMuchToWithdraw);
                    break;
                }
                case 2:
                {
                    Withdraw(savingsAccountPtr, howMuchToWithdraw); 
                    break;
                }
                case 3:
                {
                    Withdraw(creditAccountPtr, howMuchToWithdraw); 
                    break;
                }
                }
                break;
            }
            }
        }
        if (exitProgram != false) // If the user doesn't terminate the program.
        {
            std::cout << "\n\n**********************************************************************************************************************\n\n";
        }

    } while (exitProgram);

}

void Withdraw(BaseAccount* accountPtr, float amount)
{
    accountPtr->Withdraw(amount);
}


void Deposit(BaseAccount* accountPtr, float amount)
{
    accountPtr->Deposit(amount);
}

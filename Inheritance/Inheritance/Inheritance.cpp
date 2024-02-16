// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Helper.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

void Withdraw(BaseAccount* accountPtr, float amount); // Will call the correct Class's Withdraw() function


void Deposit(BaseAccount* accountPtr, float amount); // Will call the correct Class's Deposit() function



int main()
{
    // Memory detection code provided by the lecture code.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1); // set block of memory to find memory leak
    _CrtDumpMemoryLeaks();
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

// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"


int main()
{
    // Memory detection code provided by the lecture code.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1); // set block of memory to find memory leak
    _CrtDumpMemoryLeaks();
    
    SavingsAccount test = SavingsAccount(100);

     for (int i = 0; i <= 3; i++)
     {
         std::cout << test.GetBalance() << "\t" << test.GetWithdrawals() << std::endl; 
         test.Withdraw(5);
         std::cout << test.GetBalance() << "\t" << test.GetWithdrawals() << "\n\n";
    }
}



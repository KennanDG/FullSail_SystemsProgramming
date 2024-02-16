// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Helper.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"


int main()
{
    // Memory detection code provided by the lecture code.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1); // set block of memory to find memory leak
    _CrtDumpMemoryLeaks();
    
    CreditAccount test;
    test.Withdraw(30);
    std::cout << "\n$30 withdrawn:\t" << "Data: " << test.GetData() << "\tAccount Balance: " << test.GetBalance() << "\n\n";
    test.Withdraw(20);
    std::cout << "Data: " << test.GetData() << std::endl;
    test.Withdraw(1);
    std::cout << "Data: " << test.GetData() << std::endl;
    test.Deposit(39);
    std::cout << "\n$39 deposited:\t" << "Data: " << test.GetData() << "\tAccount Balance: " << test.GetBalance() << "\n\n";
    test.Deposit(15);
    std::cout << "\n$15 deposited:\t" << "Data: " << test.GetData() << "\t\tAccount Balance: " << test.GetBalance() << "\n\n";
    test.Deposit(4985);
    std::cout << "\n$4985 deposited:\t" << "Data: " << test.GetData() << "\t\tAccount Balance: " << test.GetBalance() << "\n\n";


}



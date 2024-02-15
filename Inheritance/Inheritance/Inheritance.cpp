// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CheckingAccount.h"

int main()
{
    CheckingAccount test = CheckingAccount(10.5,11);

    std::cout << test.GetBalance() << std::endl;

    test.Withdraw(5);

    std::cout << test.GetBalance() << std::endl; 
}



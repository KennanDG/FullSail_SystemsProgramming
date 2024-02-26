// Rule_Of_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Base.h"
#include "Employee.h"


int main()
{
	Base::MemoryLeak(-1); // Checks for memory leak within the program.
	
	Employee test;
	test.SetName("Mia");
	test.SetSalary(100000);
	test.DisplayRecord();
	
}



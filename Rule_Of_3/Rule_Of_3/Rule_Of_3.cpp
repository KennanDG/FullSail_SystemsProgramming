// Rule_Of_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Base.h"
#include "Employee.h"
#include "Student.h"


int main()
{
	Base::MemoryLeak(-1); // Checks for memory leak within the program.
	
	Employee test;
	test.SetName("Mia");
	test.SetSalary(100000);
	test.DisplayRecord();

	Student test2;
	test2.SetGPA(3.74f);
	test2.SetName("Abi");
	test2.DisplayRecord();
	
}



#include "Employee.h"
#include <iostream>

Employee& Employee::operator=(Employee& other)
{
	if (this != &other) // makes sure 'other' is not the same object.
	{
		SetName(other.GetName());
		SetSalary(other.mSalary);
	}
	return *this;
}


Employee::Employee(Employee& other)
{
	Employee::operator=(other);
}


Employee::~Employee()
{
	
}


void Employee::SetSalary(int newSalary)
{
	mSalary = newSalary;
}


void Employee::DisplayRecord()
{
	std::cout << "\n\nName:    " << GetName() << std::endl;
	std::cout << "Salary:  " << GetSalary() << std::endl;
}


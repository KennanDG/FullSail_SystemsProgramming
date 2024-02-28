// Rule_Of_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Employee.h"
#include "Student.h"
#include "Helper.h"


void AddRecord(std::vector<Base*>& baseVector); // Adds an Employee or student object to the baseVector.
void DisplayRecords(std::vector<Base*>& baseVector); // Displays the record of each student/employee object within the vector.
void DuplicateRecord(std::vector<Base*>& baseVector); // Duplicates an already existing record within the baseVector and adds it to the end.

std::vector<Base*> baseVector; // Vector of either Employee or Student objects casted as a Base pointer.
std::vector<const char*> employee_Student = { "1 = Employee", "2 = Student" }; // Menu for user to either pick an Employee or a Student.
// Menu used to prompt user what operation they'd like to perform.
std::vector<const char*> add_Dispay_Duplicate = { "1 = Add a record.", "2 = Display all records.", "3 = Duplicate a record.", "4 = Exit program" }; 



int main()
{
	Helper::CheckMemoryLeak(-1); // Checks for memory leak within the program.


	bool exitProgram = true;
	do
	{

		std::cout << "\n\n==================================\tWelcome to my Rule Of 3 Lab\t==================================\n\n";

		Helper::PrintMenu(add_Dispay_Duplicate);
		std::cout << "\n\n";

		// Asks user what operation they want to do and stores their response in an int variable.
		int OperationToPerform = Helper::GetValidatedInt("Which operation would you like to perform?  ", 1, 4);

		switch (OperationToPerform) // Switch case dependent on user input.
		{
		case 1: // If the user would like to add a record.
		{
			std::cout << "\n";
			Helper::PrintMenu(employee_Student);
			std::cout << "\n";
			AddRecord(baseVector);
			break;
		}
		case 2: // If the user would like to display all of the records.
		{
			DisplayRecords(baseVector);
			break;
		}
		case 3: // If the user would like to duplicate a record.
		{
			DuplicateRecord(baseVector);
			break;
		}
		case 4: // If the user wants to exit the program
		{
			for (int i = 0; i < baseVector.size();) // Deletes every pointer within the vector.
			{
				delete baseVector[i];
				i++;
			}
			exitProgram = false;
			break;
		}
		}

	} while (exitProgram);
	
}



void AddRecord(std::vector<Base*>& baseVector)
{
	// Asks user if they want to add an Employee or Student object.
	int whichToAdd = Helper::GetValidatedInt("What account type would you like to add?  ", 1, 2);
	std::cout << "\n";

	if (whichToAdd == 1)
	{
		Employee* employee = new Employee();
		
		// Asks user to insert employee's name and salary.
		// Then sets the new Employee object's member fields as such.
		char employeeName[32];
		std::cout << "What is the employee's name?  ";
		std::cin.getline(employeeName, 33);
		employee->SetName(employeeName);
		Helper::ClearInput(); // Clears the cin input buffer.
		int employeeSalary = Helper::GetValidatedInt("What is the employee's salary?  ", 1);
		employee->SetSalary(employeeSalary);

		// Upcasts new employee object into a base pointer.
		Base* castedEmployee = dynamic_cast<Base*> (employee);
		if (castedEmployee != nullptr)
		{
			baseVector.push_back(castedEmployee);
		}

	}
	else
	{
		Student* student = new Student();

		// Asks user to insert employee's name and salary.
		// Then sets the new Employee object's member fields as such.
		char studentName[32];
		std::cout << "What is the student's name?  ";
		std::cin.getline(studentName, 33);
		student->SetName(studentName); 
		Helper::ClearInput(); // Clears the cin input buffer. 
		float studentGPA = Helper::GetValidatedFloat("What is the student's GPA?  ", 0.00f, 4.00f);
		student->SetGPA(studentGPA);

		// Upcasts new employee object into a base pointer.
		Base* castedStudent = dynamic_cast<Base*> (student);
		if (castedStudent != nullptr)
		{
			baseVector.push_back(castedStudent);
		}
	}
}



void DisplayRecords(std::vector<Base*>& baseVector)
{
	if (baseVector.size() == 0) // If there are no records to show.
	{
		std::cout <<  "\n\nThere are no records available.\n\n";
	}
	
	for (int i = 0; i < baseVector.size(); i++) 
	{
		baseVector[i]->DisplayRecord();
	}
}



void DuplicateRecord(std::vector<Base*>& baseVector)
{
	if (baseVector.size() == 0)
	{
		std::cout << "\n\nThere are no records available.\n\n";
	}

	for (int i = 0; i < baseVector.size(); i++)
	{
		std::cout << "\n\nIndex:  " << i;
		baseVector[i]->DisplayRecord(); 
		std::cout << "=============================";
	}
	std::cout << "\n\n";
	if (baseVector.size() != 0)
	{
		int sizeOfVector = (baseVector.size() - 1); // Keeps track of the size of the vector.

		// Asks user for the index of the record they'd like to duplicate.
		int index = Helper::GetValidatedInt("Please enter the index of the record you want to duplicate:  ", 0, sizeOfVector);
		
		// Works around the fact that if the GetValidatedInt() method has the min & max range parameters equal to 0, the ranges are ignored.
		// This makes it that the user can only enter the number 0 if there is only 1 element in the baseVector.
		if (baseVector.size() == 1 && index != 0)
		{
			index = 0;
		}

		// Tests to see if the selected record is an employee or a student object.
		// dynamic cast will return a nullptr if the record cannot be downcasted.
		Employee* check_if_employee = dynamic_cast<Employee*> (baseVector[index]);
		Student* check_if_student = dynamic_cast<Student*> (baseVector[index]);
		if (check_if_employee != nullptr) // If the record is an employee.
		{
			Employee* employee = new Employee(*check_if_employee); // Creates a new instance of an employee.

			Base* newEmployee = dynamic_cast<Base*> (employee); // Upcasts the new employee into a Base pointer.

			baseVector.push_back(newEmployee); // Adds the new employee to baseVector.
		}
		if (check_if_student != nullptr) // If the record is a student.
		{
			Student* student = new Student(*check_if_student); // Creates a new instance of an student.

			Base* newStudent = dynamic_cast<Base*> (student); // Upcasts the new student into a Base pointer.

			baseVector.push_back(newStudent); // Adds the new student to baseVector. 
		}
	}

}

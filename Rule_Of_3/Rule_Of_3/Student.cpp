#include "Student.h"
#include <iostream>

Student& Student::operator=(Student& other)
{
	if (this != &other) // makes sure 'other' is not the same object.
	{
		SetName(other.GetName());
		SetGPA(other.GetGPA());
	}
	return *this;
}


Student::Student(Student& other)
{
	Student::operator=(other);
}


Student::~Student()
{

}


void Student::SetGPA(float newGPA)
{
	mGPA = newGPA;
}


void Student::DisplayRecord()
{
	std::cout << "\n\nName:    " << GetName() << std::endl;
	std::cout << "GPA:     " << GetGPA() << std::endl;
}


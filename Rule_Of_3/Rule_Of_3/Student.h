#pragma once
#include "Base.h"
class Student : 
	public Base
{
private:
	// Member
	float mGPA;


public:
	//Constructors
	Student(): mGPA(0.00f), Base() // Default Constructor
	{}

	Student& operator= (Student& other); // assignment operator.
	Student(Student& other); // copy constructor
	~Student(); // Destructor

	// Methods
	float GetGPA() const { return mGPA; } // Getter
	void SetGPA(float newGPA); // Setter
	void DisplayRecord(); // Displays the name and GPA of the Student object.
};


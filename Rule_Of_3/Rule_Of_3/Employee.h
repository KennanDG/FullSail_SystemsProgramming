#pragma once
#include "Base.h"


class Employee :
    public Base
{
private:
    //Member
    int mSalary;


public:
    // Constructors
    Employee() : mSalary(0), Base() // Default constructor
    {}

    Employee& operator= (Employee& other); // assignment operator
    Employee(Employee& other); // Copy constructor
    ~Employee(); // Destructor

    // Methods
    int GetSalary() const { return mSalary; } // Getter
    void SetSalary(int newSalary); // Setter
    void DisplayRecord(); // Displays name & salary to the console.
};


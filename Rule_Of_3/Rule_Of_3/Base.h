#pragma once



class Base
{
private:
	// Members
	char* mName;


public:
	// Constructors
	Base() : mName(nullptr) // Empty default constructor.
	{}
	Base& operator=(Base& other); // assignment operator
	Base(Base& other); // copy constructor
	virtual ~Base(); // Base class destructors must be virtual.


	//Methods
	void SetName(const char* source); // Setter that uses deep copy to set the mName member field.

	const char* GetName() { return mName; } // Getter method that returns mName.

	virtual void DisplayRecord() = 0; // Pure virtual function. All derived classes must override this function.

	static void MemoryLeak(int setBreak); // Checks for memory leak within the program.
};


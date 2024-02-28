#pragma once
#include "Base.h"
#include <string.h>


Base& Base::operator=(Base& other)
{
	if (this != &other) // makes sure 'other' is not the same object.
	{
		SetName(other.mName);
	}
	return *this;
}



Base::Base(Base& other)
{
	Base::operator=(other);
}



Base::~Base()
{
	delete[] mName;
}



void Base::SetName(char* newName)
{
	delete[] mName; // deletes whatever was previously in the destination parameter.

	size_t length = strlen(newName) + 1; // Adds 1 to the length of the string to account for the null terminator '\0'
	mName = new char[length]; // Allocates memory in the heap for a new char array.
	strcpy_s(mName, length, newName); // Deep copies from the source to the destination.
}


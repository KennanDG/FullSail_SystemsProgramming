#pragma once
#include "Base.h"
#include "Helper.h"

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



void Base::SetName(const char* source)
{
	Helper::CopyString(source, mName);
}



void Base::MemoryLeak(int setBreak)
{
	Helper::CheckMemoryLeak(setBreak);
}

#pragma once

class TriangleStack
{
private:
	// Members
	float mBase;
	float mHeight;
	
public:
	// Constructors
	TriangleStack(float base = 0.000f, float height = 0.000f) : mBase(base), mHeight(height) // Default constuctor
	{}
	TriangleStack& operator=(TriangleStack& other);
	TriangleStack(const TriangleStack& other) : mBase(other.GetBase()), mHeight(other.GetHeight()) // Copy Constructor
	{}
	~TriangleStack() // Destructor
	{}

	// Methods

	//Getters
	float GetBase() const { return mBase; }
	float GetHeight() const { return mHeight; }
	float GetArea() const { return ((mBase * mHeight) / 2); }

	// Setters
	void SetBase(float newBase) { mBase = newBase; };
	void SetHeight(float newHeight) { mHeight = newHeight; };


};


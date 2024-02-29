#pragma once

class TriangleHeap
{
private:
	// Members
	float* mBase = nullptr;
	float* mHeight = nullptr;

public:
	// Constructors
	TriangleHeap(float base = 0.000f, float height = 0.000f) : mBase(new float(base)), mHeight(new float(height)) // Default constructor
	{}
	TriangleHeap& operator=(TriangleHeap& other); // Assignment operator
	TriangleHeap(const TriangleHeap& other); // Copy constructor
	~TriangleHeap(); // Destructor

	// Methods

	// Getters
	float GetBase() const { return *mBase; }
	float GetHeight() const { return *mHeight; }
	float GetArea() const { return ((*mBase * *mHeight) / 2); }

	// Setters
	void SetBase(float newBase);
	void SetHeight(float newHeight);
};


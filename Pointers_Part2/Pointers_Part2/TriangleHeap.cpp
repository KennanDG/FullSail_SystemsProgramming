#include "TriangleHeap.h"

TriangleHeap& TriangleHeap::operator=(TriangleHeap& other)
{
    if (this != &other) // Makes sure it is not the same object.
    {
        TriangleHeap::SetBase(other.GetBase());
        TriangleHeap::SetHeight(other.GetHeight());
    }
    return *this;
}



TriangleHeap::TriangleHeap(const TriangleHeap& other) : mBase(new float()), mHeight(new float())
{
    TriangleHeap::SetBase(other.GetBase());
    TriangleHeap::SetHeight(other.GetHeight());
}



TriangleHeap::~TriangleHeap()
{
    delete mBase;
    delete mHeight;
}

void TriangleHeap::SetBase(float newBase)
{
    delete mBase; // Deletes the memory mBase was previously pointing to.
    mBase = new float(newBase); // Creates new memory in the heap.
}



void TriangleHeap::SetHeight(float newHeight)
{
    delete mHeight; // Deletes the memory mHeight was previously pointing to. 
    mHeight = new float(newHeight); // Creates new memory in the heap. 
}

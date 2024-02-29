#include "TriangleStack.h"

TriangleStack& TriangleStack::operator=(TriangleStack& other)
{
    if (this != &other) // Makes sure it is not the same object.
    {
        TriangleStack::SetBase(other.GetBase());
        TriangleStack::SetHeight(other.GetHeight());
    }
    return *this;
}

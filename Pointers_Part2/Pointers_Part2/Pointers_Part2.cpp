// Pointers_Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TriangleHeap.h"
#include "TriangleStack.h"
#include "Helper.h"


int AddNumbersReturnInt(int* a, int* b); // Returns sum value of the a & b int pointer parameters.
void AddNumbersReturnVoid(int a, int b, int* sum); // Adds a & b together and stores the value in the int pointer sum parameter.
void SwapValues(int* a, int* b); // Swaps the values of the two int pointer parameters with each other.

int main()
{
    Helper::CheckMemoryLeak(-1);
    
    srand((unsigned)time(NULL)); // Ensures a random number is generated every time.

    int* a = new int(Helper::RandomInt());
    int* b = new int(Helper::RandomInt());
    
    std::cout << "\n\nMemory address of 'a':  " << a << "    Value 'a' points to:  " << *a;
    std::cout << "\n\nMemory address of 'b':  " << b << "    Value 'b' points to:  " << *b << "\n\n";

    int sum = AddNumbersReturnInt(a, b);

    std::cout << "Result of AddNumbersReturnInt() method:  " << sum << "\n\n";

    std::cout << "****************************************\n\n";

    int numb = Helper::RandomInt();
    int numb2 = Helper::RandomInt();
    int* sumPtr = new int();

    AddNumbersReturnVoid(numb, numb2, sumPtr); 

    std::cout << "****************************************\n\n";

    SwapValues(a, b);

    std::cout << "****************************************\n\n"; 

    std::cout << "    Printing out the areas for the TriangleHeap objects.\n\n";

    // Declaration of 2 TriangleHeap instances.
    TriangleHeap heap1(6.057f, 9.843f); 
    TriangleHeap heap2(8.632f, 11.869f);

    std::vector<TriangleHeap> heapVector; // Vector that holds TriangleHeap variables. 
    heapVector.push_back(heap1); 
    heapVector.push_back(heap2); 

    for (int i = 0; i < heapVector.size(); i++) 
    {
        std::cout << "heap" << i + 1 << "'s area:  " << heapVector[i].GetArea() << std::endl;
    }

    std::cout << "\n\n****************************************\n\n";

    std::cout << "    Printing out the areas for the TriangleStack objects.\n\n";

    // Declaration of 2 TriangleStack instances.
    TriangleStack stack1(46.123f, 70.695f);
    TriangleStack stack2(23.468f, 55.269f);

    std::vector<TriangleStack> stackVector; // Vector that holds TriangleHeap variables. 
    stackVector.push_back(stack1);
    stackVector.push_back(stack2);

    for (int i = 0; i < stackVector.size(); i++)
    {
        std::cout << "stack" << i + 1 << "'s area:  " << stackVector[i].GetArea() << std::endl;
    }


    delete a;
    delete b;
    delete sumPtr; 
}



int AddNumbersReturnInt(int* a, int* b)
{
    int returnValue = *a + *b; // Dereferences pointer parameters and stores the sum in an int variable.
    
    return returnValue;
}



void AddNumbersReturnVoid(int a, int b, int* sum)
{
    std::cout << "Value of first int parameter:  " << a << "\nValue of second int parameter:  " << b << "\n\n";
    
    int result = a + b; // Stores the sum of the int variables.

    *sum = result; // Dereferences the sum pointer and stores the value as (a + b).

    std::cout << "Result of AddNumbersReturnVoid() method:  " << *sum << "\n\n";

}



void SwapValues(int* a, int* b)
{
    std::cout << "Testing out the SwapValues() method\n\n";
    
    std::cout << "*****  Before swap  *****\n\n";
    std::cout << "Memory address of 'a':  " << a << "    Value 'a' points to:  " << *a;
    std::cout << "\n\nMemory address of 'b':  " << b << "    Value 'b' points to:  " << *b << "\n\n";
    // Stores the values of the 2 int pointer parameters in temporary int variables.
    int tempA = *a; 
    int tempB = *b;
    // Swaps the values of the int pointers with each other.
    *a = tempB;
    *b = tempA; 

    std::cout << "*****  After swap  *****\n\n";
    std::cout << "Memory address of 'a':  " << a << "    Value 'a' points to:  " << *a;
    std::cout << "\n\nMemory address of 'b':  " << b << "    Value 'b' points to:  " << *b << "\n\n";

}

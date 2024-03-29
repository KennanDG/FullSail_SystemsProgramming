// HelperLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Helper.h"

int main()
{
    srand((unsigned)time(NULL));
    
    const char* strMessage = "Please enter a number 1-4 here: ";
    int min = 1;
    int max = 4;

    std::vector<const char*> menu = { "1) first option", "2) second option", "3) third option", "4) fourth option" };

    Helper::GetValidatedInt(strMessage, min, max);

    std::cout << Helper::RandomInt(50, 69) << std::endl;

    Helper::PrintMenu(menu);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

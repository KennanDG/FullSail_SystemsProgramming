// GauthierKennan_Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


void PrintIntAndMemory(int numb, int* pointer); // Method used to print out an int and its memory address.

enum EnumColorDefinition
{
    Red,
    Blue,
    Silver,
    White,
    Black
};


struct Car
{
public:
    // Members
    char mMake;
    char mModel;
    int mYear;
    int mMileage;
    EnumColorDefinition mColor;

    // Constructor
    Car(char make, char model, int year, int mileage, EnumColorDefinition color) : mMake(make), mModel(model), mYear(year), mMileage(mileage), mColor(color)
    {}

};




int main()
{
    srand((unsigned)time(NULL)); // Provides seed value.
    

    std::cout << "\n\n***************************\tProgram 1\t***************************\n\n";


    // First array of 15 random numbers.
    int numbArray[15];

    for (int i = 0; i < 15; i++) // Adds a random number to each index within numbArray.
    {
        numbArray[i] = rand();
    }

    for (int i = 0; i < 15; i++) // For loop to print out each number and their memory addresses.
    {
        std::cout << "Index:\t" << i << "\tValue:\t" << numbArray[i] << "\t\tMemory address:\t" << &numbArray[i] << std::endl; 

    }

    std::cout << "\n\n***************************\tProgram 2\t***************************\n\n";

    // Second array of 15 random numbers.
    int numbArray2[15]; 

    for (int i = 0; i < 15; i++) // Adds a random number to each index within numbArray.
    {
        numbArray2[i] = rand();
    }

    for (int i = 0; i < 15; i++) // For loop to print out each number and their memory addresses.
    {
        int* pointer = &numbArray2[i]; // Stores the memory address of the current iterable.

        std::cout << "Index:\t" << i << "\t";
        PrintIntAndMemory(numbArray2[i], pointer); 

    }


    std::cout << "\n\n***************************\tProgram 3\t***************************\n\n";





}




void PrintIntAndMemory(int numb, int* pointer)
{
    std::cout << "Value:\t" << numb << "\t\tMemory address:\t" << pointer << std::endl;
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
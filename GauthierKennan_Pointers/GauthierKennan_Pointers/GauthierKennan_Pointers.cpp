// GauthierKennan_Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


void PrintIntAndMemory(int numb, int* pointer); // Method used to print out an int and its memory address.

void ClearInput(); // Clears the cin buffer.


enum EnumColorDefinition // Options for the color of a car object
{
    Red,
    Blue,
    Silver,
    White,
    Black,
    Orange
};


struct Car
{
public:
    // Members
    char mMake[32];
    char mModel[32];
    int mYear;
    int mMileage;
    EnumColorDefinition mColor;

};

void GetCarInfo(Car& car); // Asks for user input to construct a car object. 

// Vector of strings to display color options to the user. To be used in the GetCarInfo() method.
std::vector<std::string> colorOptions = { "0 = Red", "1 = Blue", "2 = Silver", "3 = White", "4 = Black", "5 = Orange" };


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
    std::cout << "This program will ask you to create an array of 3 car objects.\n";

    Car arrayOfCars[3]; // An array of three car objects.

    int iterator = 1; // Keeps track of which car the user is making.

    for (int i = 0; i < 3; i++) // Asks the user to fill in the info about each car with the arrayOfCars.
    {
        std::cout << "\nFor Car " << iterator << ":\n\n";
        
        GetCarInfo(arrayOfCars[i]);

        iterator++;
    }

    int iterator2 = 1; // Keeps track of which car is being displayed.

    std::cout << "\n\n***************************\tVehicle information\t***************************\n\n";

    for (Car& car : arrayOfCars)
    {
        std::string carColor;
        switch (car.mColor)
        {
        case 0:
        {
            carColor = "Red";
            break;
        }
        case 1:
        {
            carColor = "Blue";
            break;
        }
        case 2:
        {
            carColor = "Silver";
            break;
        }
        case 3:
        {
            carColor = "White";
            break;
        }
        case 4:
        {
            carColor = "Black";
            break;
        }
        case 5:
        {
            carColor = "Orange";
            break;
        }
        }
        
        std::cout << "Car " << iterator2 << ":\t";
        std::cout << car.mYear << " ";
        std::cout << car.mColor << " ";
        std::cout << car.mMake << " ";
        std::cout << car.mModel << " with ";
        std::cout << car.mMileage << " miles";
        std::cout << "\n\n************************\n\n";
    }

}




void PrintIntAndMemory(int numb, int* pointer)
{
    std::cout << "Value:\t" << numb << "\t\tMemory address:\t" << pointer << std::endl;
}


void ClearInput()
{
    std::cin.clear(); // clears the fail FLAGS, not the buffer
    std::cin.ignore(INT_MAX, '\n'); // actually clears what was typed into the cin buffer
}



void GetCarInfo(Car& car)
{
    std::cout << "Make: "; 
    std::cin.getline(car.mMake, 32) ;
    ClearInput(); 


    std::cout << "Model: "; 
    std::cin.getline(car.mModel, 32); 
    ClearInput();

    bool condition1 = true; // exit condition for do while loop
    do
    {
        std::cout << "Year: ";
        std::string input;
        std::cin >> input; 
        try
        {
            car.mYear = std::stoi(input);
            if (car.mYear > 1886)
            {
                condition1 = false;
            }
            else
            {
                std::cout << "Cars didn't exist before then. Please try again.\n";
            }
            
        }
        catch (...)
        {
            std::cout << "Error. Please enter a valid number.\n";
        }

    } while (condition1);
    ClearInput();
    std::cout << "\n";

    bool condition2 = true; // exit condition for do while loop

    do
    {
        std::cout << "Mileage: ";
        std::string input;
        std::cin >> input; 
        try
        {
            car.mMileage = std::stoi(input);
            if (car.mMileage >= 0)
            {
                condition2 = false;
            }
            else
            {
                std::cout << "Cars can't have negative mileage. Please try again.\n";
            }
        }
        catch (...)
        {
            std::cout << "Error. Please enter a valid number.\n";
        }

    } while (condition2);
    ClearInput(); 
    std::cout << "\n"; 
    

    for (std::string color : colorOptions)
    {
        std::cout << color << std::endl;

    }
    bool condition3 = true; // exit condition for do while loop
    do
    {
        std::cout << "\nEnter a number 0-5 to select a color: ";
        std::string input;
        std::cin >> input;
        try
        {
            int selectedColor = std::stoi(input);
            if (selectedColor >= 0 && selectedColor <= 5)
            {
                car.mColor = (EnumColorDefinition)selectedColor; 
                condition3 = false;
            }
            else
            {
                std::cout << "\nError. Please enter a valid number 0-5.";
            }
        }
        catch (...)
        {
            std::cout << "\nError. Please enter a valid number 0-5.";
        }


    } while (condition3);   
    ClearInput(); 
    std::cout << "\n"; 
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
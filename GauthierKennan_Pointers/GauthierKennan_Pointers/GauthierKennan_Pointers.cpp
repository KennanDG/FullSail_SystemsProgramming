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

void RepaintCar(Car* ptrCar, EnumColorDefinition newcolor); // Method used to change the mColor member field of a Car object.

void AddMileage(Car* ptrCar, int milesToAdd); // Method used to increase the mMileage member field of a Car object.

void PrintCar(Car c); // Method used to print out information about the car object using pass by value.
void PrintCarPointer(Car* ptrCar); // Method used to print out information about the car object using pass by pointer.

// Method used to convert EnumColorDefinition value (an int) into a string representing the intended color.
std::string ShowCarColor(int colorIndex); 



// Vector of strings to display color options to the user. To be used in the GetCarInfo() method.
std::vector<std::string> colorOptions = { "0 = Red", "1 = Blue", "2 = Silver", "3 = White", "4 = Black", "5 = Orange" };

// Vector of strings to show the user they can change the color or add mileage to a car object.
std::vector<std::string> changeColorOrMileage = { "1 = Repaint car", "2 = Add mileage to car" };

// Shows the user what cars they can change.
std::vector<std::string> carSelection = { "0 = First Car", "1 = Second Car", "2 = Third Car", "3 = Exit program"};


int main()
{
    srand((unsigned)time(NULL)); // Provides seed value.

    std::cout << "\n\n***************************\tProgram 1\t***************************\n\n";
    
    int numbArray[15]; // First array of 15 random numbers.

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
    std::cout << "This program will ask you to create an array of 3 car objects and modify them.\n";

    Car arrayOfCars[3]; // An array of three car objects.

    int iterator = 1; // Keeps track of which car the user is making.

    for (int i = 0; i < 3; i++) // Asks the user to fill in the info about each car with the arrayOfCars.
    {
        std::cout << "\nFor Car " << iterator << ":\n\n";
        
        GetCarInfo(arrayOfCars[i]); // Prompts the user for what 3 cars they want to build.

        iterator++; // Increases the count of the iterator variable by 1.
    }


    std::cout << "\n\n***************************\tVehicle information\t***************************\n\n";

    int iterator2 = 1; // Keeps track of which car is being displayed.
    
    std::cout << "Printing cars using pass by value:\n\n";
    
    for (Car& car : arrayOfCars) // Prints each car using PrintCar().
    {
        std::cout << "Car " << iterator2 << ":\t"; 
        PrintCar(car); 
        iterator2++; // Increases the count of the iterator2 variable by 1. 
    }
    
    int iterator3 = 1; // Keeps track of which car is being displayed.

    std::cout << "\n\nPrinting cars using pass by pointer:\n\n";

    for (Car& car : arrayOfCars) // Prints each car using PrintCarPointer().
    {
        std::cout << "Car " << iterator3 << ":\t";
        PrintCarPointer(&car); 
        iterator3++; // Increases the count of the iterator2 variable by 1.
    }

    

    std::cout << "\n\n***************************\tChange color or Add mileage\t***************************\n\n";

    bool exitProgram = true; // exit condition for do while loop.

    do
    {
        int iterator4 = 1; // Keeps track of which car is being displayed. 
        int carIndex; // Stores user's choice for which car to change.
        int change; // Stores user's choice to change the car's color or add miles.
        int selectedColor; // New color selected by the user
        int addedMiles; // Amount of miles to add to the mMileage member field chosen by the user.
        EnumColorDefinition newColor; // selectedColor casted as an enum for the EnumColorDefinition.

        // Exit conditions for their respective do while loops.
        bool selectCarToChangeCondition = true; 
        bool selectColorOrMilesCondition = true; 
        bool selectColorCondition = true; 
        bool changeMilesCondition = true;
        
        for (Car& car : arrayOfCars) // Prints each car using PrintCarPointer().
        {
            std::cout << "Car " << iterator4 << ":\t";
            PrintCarPointer(&car);
            iterator4++; // Increases the count of the iterator2 variable by 1.
        }


        for (std::string carOption : carSelection) // Prints out which car the user would like to change.
        {
            std::cout << "\t" << carOption; 
        }
        std::cout << "\n\n"; 

        // Asks the user which car they would like to change.
        do
        {
            std::cout << "Enter either 0, 1, or 2 for which car would you like to change (Enter 3 to exit the program): ";
            std::string selection; 
            std::cin >> selection; 
            try
            {
                carIndex = std::stoi(selection);  
                if (carIndex == 0 || carIndex == 1 || carIndex == 2) 
                {
                    selectCarToChangeCondition = false; 
                }
                else if (carIndex == 3)
                {
                    selectCarToChangeCondition = false;
                    exitProgram = false;
                }
                else
                {
                    std::cout << "Error. Please enter 0, 1, or 2.\n";
                }

            }
            catch (...)
            {
                std::cout << "Error. Please enter 0, 1, or 2.\n";
            }

        } while (selectCarToChangeCondition);
        ClearInput(); 
        std::cout << "\n"; 

        if (carIndex == 3) // If the user decides to exit the program.
        {
            continue; // Skips over the rest of the 'exitProgram' do while loop.
        }


        for (std::string option : changeColorOrMileage) // Prints out 2 options to change a car's color or add miles.
        {
            std::cout << "\t" << option << "\t";
        }
        std::cout << "\n\n";


        // Asks the user if they want to change the car's color or add mileage to the vehicle.
        do
        {
            std::cout << "Please enter 1 or 2 to change the color or add miles to a car: ";
            std::string selection;
            std::cin >> selection;
            try
            {
                change = std::stoi(selection);
                if (change == 1 || change == 2)
                {
                    selectColorOrMilesCondition = false;
                }
                else
                {
                    std::cout << "Error. Please enter 1 or 2.\n";
                }

            }
            catch (...)
            {
                std::cout << "Error. Please enter 1 or 2.\n";
            }
        } while (selectColorOrMilesCondition);
        ClearInput();
        std::cout << "\n";


        if (change == 1) // If the user chose to change a car's color
        {
            for (std::string colorOption : colorOptions) 
            {
                std::cout << "     " << colorOption; 
            }
            std::cout << "\n\n";
            
            // Asks the user what color they'd like to change the color to.
            do
            {
                std::cout << "\nEnter a number 0-5 to select a color: "; 
                std::string input; 
                std::cin >> input; 
                try
                {
                    int selectedColor = std::stoi(input); 
                    if (selectedColor >= 0 && selectedColor <= 5) // Checks if the number entered is between 0-5. 
                    {
                        newColor = (EnumColorDefinition)selectedColor; 
                        selectColorCondition = false; 
                    }
                    else
                    {
                        std::cout << "\nError. Please enter a valid number 0-5.";
                    }
                }
                catch (...) // If the string cannot be converted into an int.
                {
                    std::cout << "\nError. Please enter a valid number 0-5.";
                }



            } while (selectColorCondition);
            ClearInput(); 
            std::cout << "\n"; 

            RepaintCar(&arrayOfCars[carIndex], newColor); // Changes the mColor member field of the selected car object.

        }


        if (change == 2) // If the user chose to change a car's mileage.
        {
            // Asks the user how many miles to add to the car.
            do
            {
                std::cout << "How many miles would you like to add to the car: ";
                std::string enteredMilesByUser; 
                std::cin >> enteredMilesByUser;
                try
                {
                    addedMiles = std::stoi(enteredMilesByUser);
                    if (addedMiles >= 0)
                    {
                        changeMilesCondition = false;
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

            } while (changeMilesCondition);
            ClearInput();
            std::cout << "\n";

            // Adds the amount of miles chosen by the user to the mMileage member field.
            AddMileage(&arrayOfCars[carIndex], addedMiles);

        }

    } while (exitProgram); 

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
            if (car.mYear > 1886) // Checks for an appropriate year for a vehicle.
            {
                condition1 = false;
            }
            else
            {
                std::cout << "Cars didn't exist before then. Please try again.\n";
            }
            
        }
        catch (...) // If the string cannot be converted into an int.
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
            if (car.mMileage >= 0) // Checks if number entered is positive or equals to zero.
            {
                condition2 = false;
            }
            else
            {
                std::cout << "Cars can't have negative mileage. Please try again.\n";
            }
        }
        catch (...) // If the string cannot be converted into an int.
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
            if (selectedColor >= 0 && selectedColor <= 5) // Checks if the number entered is between 0-5.
            {
                car.mColor = (EnumColorDefinition)selectedColor; 
                condition3 = false;
            }
            else
            {
                std::cout << "\nError. Please enter a valid number 0-5.";
            }
        }
        catch (...) // If the string cannot be converted into an int.
        {
            std::cout << "\nError. Please enter a valid number 0-5.";
        }

    } while (condition3);   
    ClearInput(); 
    std::cout << "\n"; 
}



void RepaintCar(Car* ptrCar, EnumColorDefinition newColor)
{
    ptrCar->mColor = newColor; 
}

void AddMileage(Car* ptrCar, int milesToAdd) 
{
    ptrCar->mMileage += milesToAdd;
}



void PrintCar(Car car)
{
    std::string carColor = ShowCarColor(car.mColor);

    std::cout << car.mYear << " "; 
    std::cout << carColor << " "; 
    std::cout << car.mMake << " "; 
    std::cout << car.mModel << " with "; 
    std::cout << car.mMileage << " miles";
    std::cout << "\n\n////////////////////////\n\n";

}

void PrintCarPointer(Car* ptrCar) 
{
    PrintCar(*ptrCar);
}


std::string ShowCarColor(int colorIndex)
{
    std::string carColor; // Stores what color the car will be as a string.
    switch (colorIndex) // will set carColor string as one of the colors based on the enum value of the mColor member field
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
    return carColor;
}


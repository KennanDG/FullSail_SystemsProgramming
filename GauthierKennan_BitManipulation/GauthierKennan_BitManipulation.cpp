// GauthierKennan_BitManipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


unsigned int bitField = 19; // Global Value


std::string ConvertToBinary(unsigned int numb); // Method used to convert a number into its binary format.

void TurnOn(int bitIndex); // Method used to "turn on" (change from 0 to 1) a bit at a specific index.

void TurnOff(int bitIndex); // Method used to "turn off" (change from 1 to 0) a bit at a specific index. 

void Toggle(int bitIndex); // Method used to "toggle" (0 becomes 1 and vice versa) a bit at a specific index.

void Negate(unsigned int numb); // Inverts all of the bits within the numb int parameter. 

void LeftShift(unsigned int numb); // Left shifts the numb int parameter by 1.

void RightShift(unsigned int numb); // Right shifts the numb int parameter by 1.




int main()
{
    std::cout << "\n\n========================\tWelcome to my Bit Manipulation Lab\t========================\n\n";

    std::cout << "The value of my global bit field is: " << bitField << std::endl;
    std::cout << "And it's value in binary is: " << ConvertToBinary(bitField) << "\n\n";



    std::cout << "****************************************************************************\n\n";
    std::cout << "Which operation would you like to perform?\n\n";


    bool condition = true; // exit condition for do while loop.


    // Vector of strings used to prompt user which bitwise operation they want to perform on the bitField unsinged int.
    std::vector<std::string> bitwiseOperations = { "1 = TurnOff", "2 = TurnOff", "3 = Toggle", "4 = Negate", "5 = LeftShift", "6 = RightShift", "7 = Exit Program"};

    
    for (std::string bitwise : bitwiseOperations) 
    {
        std::cout << bitwise << std::endl; 
    }

    // Prompts user for input and stores it in a string variable.
    std::cout << "\nPlease enter a number 1-7 here: ";
    std::string userInput;
    std::cin >> userInput;
    std::cin.clear(); 
    std::cin.ignore(INT_MAX, '\n');

    try
    {
        int switchCase = std::stoi(userInput);
    }
    catch (...)
    {

    }
    
    // switch(userInput)




    //do
    //{
    //    std::cout << "****************************************************************************\n\n"; 
    //    std::cout << "Which operation would you like to perform?\n\n";



    //    for (std::string bitwise : bitwiseOperations) 
    //    {
    //        std::cout << bitwise << std::endl; 
    //    }


    //    // Prompts user for input and stores it in a string variable.
    //    std::cout << "\nPlease enter a number 1-7 here: ";
    //    std::string userInput;
    //    std::cin >> userInput;
    //    std::cin.clear();
    //    std::cin.ignore(INT_MAX, '\n');



    //} while (condition);



}




std::string ConvertToBinary(unsigned int numb)
{
    std::string result;

    const int totalBits = sizeof(int) * 8; // Variable used to represent the amount of bits in an int data type (32).

    for (int i = 1; i <= totalBits; i++) // Loops 32 times
    {
        // Checks if the bit index is turned on (is 1) or is turned off (is 0)
        // starting at the 32nd index.
        if (numb & (1 << (totalBits - i) ) ) 
        {
            result += "1"; // Appends "1" to the string return variable if the bit index is on.
        }
        else
        {
            result += "0"; // Appends "0" to the string return variable if the bit index is off.
        }
    }
    
    return result;
}



void TurnOn(int bitIndex)
{
    bitField |= (1 << bitIndex);
}


void TurnOff(int bitIndex)
{
    bitField &= ~(1 << bitIndex);
}

void Toggle(int bitIndex)
{
    bitField ^= (1 << bitIndex);
}

void Negate(unsigned int numb)
{
    bitField = ~numb;
}

void LeftShift(unsigned int numb)
{
    bitField = numb << 1; 
}

void RightShift(unsigned int numb)
{
    bitField = numb >> 1; 
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
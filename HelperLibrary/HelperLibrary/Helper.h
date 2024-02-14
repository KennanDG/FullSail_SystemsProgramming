#pragma once
#include <iostream>
#include <vector>



namespace Helper
{
	void ClearInput() // Method used to clear buffer from cin.
	{
		std::cin.clear(); // clears the fail FLAGS, not the buffer
		std::cin.ignore(INT_MAX, '\n'); // actually clears what was typed into the cin buffer
	}


	
	int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0)
	{
		bool exitCondition = true;
		do
		{
			std::cout << strMessage; // Message to prompt user for input.

			int input; // Number entered by the user. 

			if (std::cin >> input) // Checks if the data entered can be stored in an int variable.
			{
				if (input >= nMinimumRange && input <= nMaximumRange) // Checks if input entered is within range.
				{
					ClearInput(); 
					return input; 
					exitCondition = false; 
				}
				else if (nMinimumRange == 0 && nMaximumRange == 0) // Ignores range and accepts any integer.
				{
					ClearInput();
					return input;
					exitCondition = false;
				}
				else // If input is not within range.
				{
					ClearInput(); 
					std::cout << "\nError. Invalid input, please try again.\n\n";
				}
			}
			else // If input cannot be stored in an int data type.

			{
				ClearInput();
				std::cout << "\nError. Invalid input, please try again.\n\n";
			}

		} while (exitCondition); 

	}



	int RandomInt(int minRange = 0, int maxRange = 0) // Returns a random integer within a given range (optional)
	{
		srand((unsigned)time(NULL)); // Ensures a random number is generated every time.

		int randomNumber = 0; // Random integer to be returned.

		if (minRange != 0 && maxRange != 0) // If theres a desired range to generate a number from.
		{
			int range = maxRange - (minRange - 1); // Ensures the randomly generated number stays within the desired range.
			randomNumber = minRange + (rand() % range);
		}
		else if (minRange != 0) // If there is a minimum range. 
		{
			randomNumber = minRange + rand();
		}
		else if (maxRange != 0) // If there is a maximum range.
		{
			randomNumber = rand() % (maxRange + 1); // The +1 makes the maxRange inclusive.
		}
		else // If there is no desired range.
		{
			randomNumber = rand();
		}

		return randomNumber;
	}
	


	void PrintMenu(std::vector<const char*&> menu)
	{

	}


}
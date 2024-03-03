#include "encryptMessageBackward.h"
#include "encryptionMenu.h" // struct object stored in ecryptionMenu.h file

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

// encrypts the inputed message backward
// menuOptions is an object that stores the users choice, shift, and message;
std::string encryptMessageBackward(EncryptMenu menuOptions)
{
	// trasnform message into all caps
	std::transform(menuOptions.message.begin(), menuOptions.message.end(), menuOptions.message.begin(), toupper);

	// declare messageArr with user inputed message
	std::string messageArr{ menuOptions.message };

	// JUST FOR REFERENCE
	/*std::vector<int> alphabet = { 0, 1 , 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27 };*/
	/*std::vector<int> alphabet = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 32 };*/

	std::vector<int> letterValues{};
	// iterates through the original message 
	// and transforms char values from (65-90)
	// to (0-27) under certain conditions
	for (unsigned i = 0; i < messageArr.size(); ++i)
	{
		if (messageArr.at(i) == 32)
		{
			letterValues.push_back(static_cast<int>(26));
		}
		else if (messageArr.at(i) > 32 && messageArr.at(i) < 65)
		{
			letterValues.push_back(static_cast<int>(messageArr.at(i)));
		}
		else
		{
			letterValues.push_back(static_cast<int>(messageArr.at(i) - 65));
		}

		/*std::cout << letterValues.at(i) << " ";*/
	}

	std::vector<int> encryptedIntArr{};
	int prevShiftVal{};
	int notLetterCount{};
	int checkVal{};

	// Iterates through the letterValues 
	// determines conditions for encryption 
	// at each index of string
	for (unsigned i = 0; i < letterValues.size(); ++i)
	{
		// letters value is not in range (0-27) (i.e. a = 0, z = 26, space = 27)
		if (!(letterValues.at(i) >= 0 && letterValues.at(i) < 27))
		{
			encryptedIntArr.push_back(letterValues.at(i));
			++notLetterCount;
			continue;
		}

		// for the first index only shift forward by inputed shift
		if (i == 0)
		{
			prevShiftVal = menuOptions.shift;

			int remainder{ ((prevShiftVal + letterValues.at(0)) % 27 + 27) % 27 };

			if ((prevShiftVal + letterValues.at(0)) > 26)
			{
				encryptedIntArr.push_back(0 + remainder);
			}
			else
			{
				encryptedIntArr.push_back(prevShiftVal + letterValues.at(0));
			}

		}
		// all other characters in string
		else
		{
			// their was not a letter (i.e .,/+= )
			// get shift from letter before non-letter character
			// and shift inputed amount
			if (notLetterCount > 0)
			{
				prevShiftVal = encryptedIntArr.at(i - notLetterCount - 1) + menuOptions.shift;
				notLetterCount = 0;
			}
			else // proced to follow inputed shift pattern for value before
			{
				prevShiftVal = encryptedIntArr.at(i - 1) + menuOptions.shift;
			}

			// check values over 26 and get remainder
			checkVal = ((prevShiftVal + letterValues.at(i)) % 27 + 27) % 27;
			if (checkVal >= 26 || checkVal <= 26)
			{
				/*add the remanider to 0 (i.e A + shift)*/
				encryptedIntArr.push_back(0 + checkVal);
			}
			// values within range (0-27)
			else 
			{
				encryptedIntArr.push_back(prevShiftVal + letterValues.at(i));
			}

		}
		/*std::cout << encryptedIntArr.at(i) << " ";*/
	}

	// iterate through the encrypted integers
	// and convert back to the char range of (65-90, 32) 
	// based on certain conditions
	std::string encryptedStringArr;
	for (unsigned i = 0; i < encryptedIntArr.size(); ++i)
	{
		// values not in range (0 - 27), put in string as inputed
		if (encryptedIntArr.at(i) > 27)
		{
			encryptedStringArr += static_cast<char>(encryptedIntArr.at(i));
		}
		// value is a space so add a space to encrypted string
		else if (encryptedIntArr.at(i) == 26)
		{
			encryptedStringArr += " ";
		}
		// value is within range 0 - 27, add 65 to get back between 65 - 90
		else
		{
			encryptedStringArr += static_cast<char>(encryptedIntArr.at(i) + 65);
		}
	}

	/*std::cout << encryptedStringArr << '\n';*/

	// reverse the string
	std::reverse(encryptedStringArr.begin(), encryptedStringArr.end());

	return encryptedStringArr;
}
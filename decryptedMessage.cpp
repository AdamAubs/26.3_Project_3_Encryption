#include "encryptionMenu.h"
#include "decryptedMessage.h"

#include <iostream>
#include <vector>
#include <algorithm>


std::string decryptedMessage(EncryptMenu menuOptions)
{

	std::transform(menuOptions.message.begin(), menuOptions.message.end(), menuOptions.message.begin(), toupper);
	std::string messageArr{ menuOptions.message };
	/*std::vector<int> alphabet = { 0, 1 , 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27 };*/
	std::vector<int> alphabet = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 32 };

	std::vector<int> letterValues{};
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

	for (unsigned i = 0; i < letterValues.size(); ++i)
	{
		if (!(letterValues.at(i) >= 0 && letterValues.at(i) < 27))
		{
			encryptedIntArr.push_back(letterValues.at(i));
			++notLetterCount;
			continue;
		}

		if (i == 0)
		{
			prevShiftVal = menuOptions.shift;
			encryptedIntArr.push_back(letterValues.at(0) - prevShiftVal);
		}
		else
		{
			if (notLetterCount > 0)
			{
				prevShiftVal += encryptedIntArr.at(i - notLetterCount - 1) + menuOptions.shift;
				/*std::cout << "PrevshiftVal1: " << prevShiftVal << '\n';*/
				notLetterCount = 0;
			}
			else
			{
				prevShiftVal += encryptedIntArr.at(i - 1) + menuOptions.shift;
			}

			/*std::cout << "Prevshiftval: " << prevShiftVal << '\n';*/
			/*std::cout << letterValues.at(0) << " ";
			std::cout << letterValues.at(1) << " ";
			std::cout << letterValues.at(2) << " ";
			std::cout << letterValues.at(3) << " ";
			std::cout << letterValues.at(4) << " ";*/
			/*if (i == 4)
			{
				std::cout << "Letter Value: " << letterValues.at(4) << " ";
				std::cout << "PreshiftVal: " << prevShiftVal << " " << '\n';
			}*/

			/*if (letterValues.at(i) == 19)
			{
				std::cout << "PreshiftVal check: " << prevShiftVal << '\n';
			}*/

			/*if ((prevShiftVal - letterValues.at(i)) < 0)
			{
				prevShiftVal = fabs(letterValues.at(i) + prevShiftVal);
			}*/

			if ((prevShiftVal) > 27)
			{
				prevShiftVal = prevShiftVal - 27;

				while (prevShiftVal > 26)
				{
					prevShiftVal = prevShiftVal - 27;
				}

				if ((letterValues.at(i) - prevShiftVal) < 0)
				{
					encryptedIntArr.push_back(27 + letterValues.at(i) - prevShiftVal);
				}
				else
				{
					encryptedIntArr.push_back(letterValues.at(i) - prevShiftVal);
				}
			}
			else if ((letterValues.at(i) - prevShiftVal) < 0)
			{
				encryptedIntArr.push_back(27 + letterValues.at(i) - prevShiftVal);
			}
			else
			{
				encryptedIntArr.push_back(abs(letterValues.at(i) - prevShiftVal));
			}

		}
		/*std::cout << encryptedIntArr.at(i) << " " << '\n';*/
	}

	/*std::cout << encryptedIntArr.at(0) << " ";*/
	/*std::cout << encryptedIntArr.at(1) << " ";
	std::cout << encryptedIntArr.at(2) << " ";
	std::cout << encryptedIntArr.at(3) << " ";
	std::cout << encryptedIntArr.at(4) << " ";
	std::cout << encryptedIntArr.at(5) << " ";*/
	/*std::cout << encryptedIntArr.at(6) << " ";
	std::cout << encryptedIntArr.at(7) << " ";
	std::cout << encryptedIntArr.at(8) << " ";
	std::cout << encryptedIntArr.at(9) << " ";
	std::cout << encryptedIntArr.at(10) << " ";
	std::cout << encryptedIntArr.at(11) << " ";*/

	std::string encryptedStringArr;
	for (unsigned i = 0; i < encryptedIntArr.size(); ++i)
	{
		if (encryptedIntArr.at(i) > 27)
		{
			/*encryptedStringArr += static_cast<char>(encryptedIntArr.at(i));*/
			encryptedStringArr += static_cast<char>(encryptedIntArr.at(i));
		}
		else if (encryptedIntArr.at(i) == 26)
		{
			encryptedStringArr += " ";
		}
		else
		{

			/*int num = encryptedIntArr.at(i);*/
			/*std::cout << encryptedIntArr.at(i) << " ";*/
			encryptedStringArr += static_cast<char>(encryptedIntArr.at(i) + 65);
			/*std::cout << static_cast<char>(alphabet.at(static_cast<size_t>(encryptedIntArr.at(i))));*/
			/*std::cout << static_cast<char>(alphabet.at(static_cast<size_t>(num)));*/
			/*encryptedStringArr += static_cast<char>(alphabet.at(static_cast<size_t>(num)));*/
		}

	}

	/*std::cout << encryptedStringArr << '\n';*/

	return encryptedStringArr;
}
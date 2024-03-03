#include "encryption.h"
#include "encryptionMenu.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

std::string encryptMessageForward(EncryptMenu menuOptions);
std::string encryptMessageBackward(EncryptMenu menuOptions);

std::string decryptedMessage(EncryptMenu menuOptions);
std::string decryptedMessageBackward(EncryptMenu menuOptions);

std::string showDecryptedPossibilities(menuChoices);

EncryptMenu getChoice(EncryptMenu menuOptions)
{
	std::cout << "1. Encrypt message\n";
	std::cout << "2. Decrypt message\n";
	std::cout << "3. Show decrypted possibilities\n";
	std::cout << "4. Break code\n";

	std::cout << "Enter choice: ";
	std::cin >> menuOptions.choice;
	std::cout << "Enter shift (1-26): ";
	std::cin >> menuOptions.shift;
	std::cout << "Enter direction (f or b): ";
	std::cin >> menuOptions.direction;
	std::cout << "Enter message: ";
	std::getline(std::cin >> std::ws, menuOptions.message);

	return menuOptions;
}

int main()
{
	EncryptMenu menuOptions{ };

	EncryptMenu menuChoices = getChoice(menuOptions);


	if (menuChoices.choice == 2 && menuChoices.direction == 'f')
	{
		std::cout << decryptedMessage(menuChoices) << '\n';
	} else if (menuChoices.choice == 2 && menuChoices.direction == 'b')
	{
		std::cout << decryptedMessageBackward(menuChoices) << '\n';
	}
	else if (menuChoices.choice == 1 && menuChoices.direction == 'f')
	{
		std::cout << encryptMessageForward(menuChoices) << '\n';
	}
	else if (menuChoices.choice == 1 && menuChoices.direction == 'b')
	{
		std::cout << encryptMessageBackward(menuChoices) << '\n';
	}
	else if (menuChoices.choice == 3)
	{
		std::cout << showDecryptedPossibilities(menuChoices) << '\n';
	}





















































	return 0;
}



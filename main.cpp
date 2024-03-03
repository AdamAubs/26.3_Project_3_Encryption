#include "decryptedMessageForward.h"
#include "decryptedMessageBackward.h"
#include "encryptMessageForward.h"
#include "encryptMessageBackward.h"
#include "showDecryptPossibilities.h"

#include "encryptionMenu.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


// print menu with choices
EncryptMenu getChoice(EncryptMenu menuOptions)
{
	std::cout << "1. Encrypt message\n";
	std::cout << "2. Decrypt message\n";
	std::cout << "3. Show decrypted possibilities\n";
	std::cout << "4. Break code\n";
	
	std::cout << "Enter choice: ";
	std::cin >> menuOptions.choice;
	if (menuOptions.choice == 1 || menuOptions.choice == 2)
	{
		std::cout << "Enter shift (1-26): ";
		std::cin >> menuOptions.shift;
		std::cout << "Enter direction (f or b): ";
		std::cin >> menuOptions.direction;
	}
	
	std::cout << "Enter message: ";
	std::getline(std::cin, menuOptions.message);
	std::getline(std::cin, menuOptions.message);

	return menuOptions;
}

int main()
{
	// initialize menuOptions obj to acess choice, shift, direction, message
	EncryptMenu menuOptions{ };

	EncryptMenu menuChoices = getChoice(menuOptions);

	// Decrypt forward
	if (menuChoices.choice == 2 && menuChoices.direction == 'f')
	{
		std::cout << "Decrypted message: " << decryptedMessage(menuChoices) << '\n';
	} 
	// Decrypt backward
	else if (menuChoices.choice == 2 && menuChoices.direction == 'b')
	{
		std::cout << "Decrypted message: " << decryptedMessageBackward(menuChoices) << '\n';
	}
	// Encrypt forward
	else if (menuChoices.choice == 1 && menuChoices.direction == 'f')
	{
		std::cout << "Encrypted message: " << encryptMessageForward(menuChoices) << '\n';
	}
	// Encrypt backward
	else if (menuChoices.choice == 1 && menuChoices.direction == 'b')
	{
		std::cout << "Encrypted message: " << encryptMessageBackward(menuChoices) << '\n';
	}
	else if (menuChoices.choice == 3)
	{
		showDecryptPossibilities(menuChoices);
	}
	return 0;
}



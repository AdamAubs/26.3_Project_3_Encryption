#include "showDecryptPossibilities.h"
#include "decryptedMessageForward.h"
#include "decryptedMessageBackward.h"

#include <iostream>

void showDecryptPossibilities(EncryptMenu menuOptions)
{
	for (unsigned i = 1; i <= 26; ++i)
	{
		menuOptions.shift = static_cast<int>(i);
		std::cout << i << "f: " << decryptedMessage(menuOptions) << '\n';
		std::cout << i << "b: " << decryptedMessageBackward(menuOptions) << '\n';
	}

	
}
#include "encryptionMenu.h"
#include <iostream>
#include <string>
#include "encryption.h"

struct EncryptMenu
{
	int choice{};
	int shift{ };
	char direction{};
	/*W message{ "And, now, for the backwards choice" };*/
	//std::string message{};
	std::string message{};
	/*W message{ "IFMMP" };*/
};
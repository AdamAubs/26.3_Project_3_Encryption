#include "breakTheCode.h"
#include "decryptedMessageForward.h"
#include "decryptedMessageBackward.h"

#include <iostream>
#include <sstream>
#include <vector>

// POSSIBILY IMPLEMENT LATER
//struct commonWordTracker {
//    int commonWordCount{};
//    std::string message;
//};

void tryAllPossibilities(EncryptMenu menuOptions)
{

    /*commonWordTracker forwardTracker;
    commonWordTracker backwardTracker;*/

    std::vector<std::string> commonWordsList = { "THE", "BE", "TO", "OF", "AND", "A", "IN", "THAT", "HAVE", "I" };
    int commonWordCountFwd{ 0 };
    int highestCommonWordCountFwd{ 0 };
    int firstCommonWordFoundFwd{ 0 };
    std::string highestCommonMessageFwd;

    int commonWordCountBwd{ 0 };
    int highestCommonWordCountBwd{ 0 };
    int firstCommonWordFoundBwd{ 0 };
    std::string highestCommonMessageBwd;

    for (unsigned i = 1; i <= 26; ++i)
    {
        menuOptions.shift = static_cast<int>(i);
        
        std::string decryptedMessageStrFwd{ decryptedMessage(menuOptions) };
       
        std::stringstream messageDecryptForwardStream(decryptedMessageStrFwd);
        
        while (!(messageDecryptForwardStream.eof()))
        {
            std::string word;
            messageDecryptForwardStream >> word;
            for (unsigned j = 0; j < commonWordsList.size(); ++j)
            {
                if (commonWordsList.at(j) == word)
                {
                    commonWordCountFwd++;
                }
            }
            
        }
        if (commonWordCountFwd > highestCommonWordCountFwd)
        {
            int temp = highestCommonWordCountFwd;
            highestCommonWordCountFwd = commonWordCountFwd;
            commonWordCountFwd = temp;
            highestCommonMessageFwd = decryptedMessageStrFwd;

            firstCommonWordFoundFwd = static_cast<int>(i);
        }
        commonWordCountFwd = 0;


        /*std::cout << i << "f: " << decryptedMessage(menuOptions) << " " << highestCommonWordCountFwd << '\n';*/

        

        std::string decryptBackwardStr(decryptedMessageBackward(menuOptions));
        std::stringstream messageDecryptBackwardStream(decryptBackwardStr);

        while (!(messageDecryptBackwardStream.eof()))
        {
            std::string word;
            messageDecryptBackwardStream >> word;
            for (unsigned j = 0; j < commonWordsList.size(); ++j)
            {
                if (commonWordsList.at(j) == word)
                {
                    commonWordCountBwd++;
                }
            }
        }

        if (commonWordCountBwd > highestCommonWordCountBwd)
        {
            int temp = highestCommonWordCountBwd;
            highestCommonWordCountBwd = commonWordCountBwd;
            commonWordCountBwd = temp;
            highestCommonMessageBwd = decryptBackwardStr;

            firstCommonWordFoundBwd = static_cast<int>(i);
        }
        commonWordCountBwd = 0;

        /*std::cout << i << "b: " << decryptedMessageBackward(menuOptions) << " " << highestCommonWordCountBwd << '\n';*/
    }

    if (highestCommonWordCountBwd > highestCommonWordCountFwd)
    {
        std::cout << "Decrypted message is: " << highestCommonMessageBwd;
    }
    else if (highestCommonWordCountBwd < highestCommonWordCountFwd)
    {
        std::cout << "Decrypted message is: " << highestCommonMessageFwd;
    }
    else if ((highestCommonWordCountBwd == highestCommonWordCountFwd) && (firstCommonWordFoundBwd < firstCommonWordFoundFwd))
    {
        std::cout << "Decrypted message is: " << highestCommonMessageBwd;
    } 
    else if ((highestCommonWordCountBwd == highestCommonWordCountFwd) && (firstCommonWordFoundFwd < firstCommonWordFoundBwd))
    {
        std::cout << "Decrypted message is: " << highestCommonMessageFwd;
    }
    else if (highestCommonWordCountBwd == 0 && highestCommonWordCountFwd == 0)
    {
        std::cout << "Unable to find a decrypted message.";
    }
}
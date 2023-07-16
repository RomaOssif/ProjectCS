#include "MorseCode.hpp"
#include "CaesarCipher.hpp"
#include "Substitution.hpp"
#include <iostream>
#include <string>

using namespace std;

const string tests[] =
{
    "911",
    "Hello everybody!",
    "One to the one to the one to the three",
    "Hmmm...?",
    "abcd efgh ijkl mnop qrst uvw xyz",
    "ABCD EFGH IJKL MNOP QRST UVW XYZ",
    "! ? . ( ) , : ; _ _ - ( ) / \\ well well?",
    "To add a new test, just add here a few new strings!"
};

//A method for testing a specific coding with tests above
void testCoding(Coding* coding, string codingName)
{
    for (string test : tests)
    {
        string encodedText = coding->Encode(test);

        cout << "Title: \"" << test << "\"\n";
        cout << codingName << ": \"" << encodedText << "\"\n";
        cout << "Again: \"" << coding->Decode(encodedText) << "\"\n";

        cout << "\n";
    }
}

int main()
{
    cout << "This project has implemented 3 encryption classes: Morse code, Caesar Cipher, and Substitution Cipher.\n";
    cout << "Each of them is capable of encoding and decoding text, whether in a string or a file.\n";
    cout << "Print [Exit] in the main menu to terminate the program.\n";

    //testCoding(new MorseCode(), "Morse");

    Coding* coding;
    while(true)
    {
        coding = nullptr;

        cout << "\nChoose a cipher you would like to use: [Caesar], [Morse], [Substitution]: ";

        string cipherChoice;
        cin >> cipherChoice;

        if(cipherChoice == "Exit")
        {
            cout << "Exiting the program...\n";

            delete coding;
            break;
        }

        if (cipherChoice == "Caesar")
        {
            cout << "Enter a numeric key for Caesar Cipher (can be negative): ";

            int key;
            cin >> key;

            coding = new CaesarCipher(key);
        }

        else if (cipherChoice == "Morse")
        {
            coding = new MorseCode();
        }

        else if (cipherChoice == "Substitution")
        {
            cout << "Enter a 26-long string key for the cipher or proceed with [Default]: ";

            string key;
            cin >> key;

            if (key == "Default")
            {
                key = "DQRSGKZEFHIJYLMUOPABCTXVWN";
            }

            coding = new Substitution(key);
        }

        else
        {
            cout << "Wrong input. Did you start with the capital letter?\n";
            continue;
        }

        cout << "Would you like to [Encode] or [Decode]: ";

        string operationChoice;
        cin >> operationChoice;

        if (operationChoice == "Encode")
        {
            cout << "Would you like to encode a [File] or a [String]: ";

            string argumentChoice;
            cin >> argumentChoice;

            if (argumentChoice == "File")
            {
                cout << "Provide the file to encode: ";

                string fileName;
                cin.ignore();
                getline(cin, fileName);

                coding->EncodeFile("Files/" + fileName, "Files/Encoded_" + fileName);

                cout << "The file has been saved in the Files folder with the name Encoded_" + fileName << "!\n";
            }

            else if (argumentChoice == "String")
            {
                cout << "Provide the string to encode: ";

                string toEncode;
                cin.ignore();
                getline(cin, toEncode);

                cout << "Encoded string: \"" << coding->Encode(toEncode) << "\".\n";
            }

            else
            {
                cout << "Wrong input. Did you start with the capital letter?\n";

                delete coding;
                continue;
            }
        }

        else if(operationChoice == "Decode")
        {
            cout << "Would you like to decode a [File] or a [String]: ";

            string argumentChoice;
            cin >> argumentChoice;

            if (argumentChoice == "File")
            {
                cout << "Provide the file to decode: ";

                string fileName;
                cin.ignore();
                getline(cin, fileName);

                coding->DecodeFile("Files/" + fileName, "Files/Decoded_" + fileName);

                cout << "The file has been saved in the Files folder with the name Decoded_" << fileName << "!\n";
            }

            else if (argumentChoice == "String")
            {
                cout << "Provide the string to decode: ";

                string toDecode;
                cin.ignore();
                getline(cin, toDecode);

                cout << "Decoded string: \"" << coding->Decode(toDecode) << "\".\n";
            }

            else
            {
                cout << "Wrong input. Did you start with the capital letter?\n";

                delete coding;
                continue;
            }
        }

        else
        {
            cout << "Wrong input. Did you start with the capital letter?\n";

            delete coding;
            continue;
        }

        delete coding;
    }

    return 0;
}
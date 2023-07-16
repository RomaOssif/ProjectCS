#include "CaesarCipher.hpp"
#include <map>
#include <iostream>
#include <string>

using namespace std;

map<char, char> CaesarCipher::SetTranslation(int shiftBy)
{
    map<char, char> translation;

    shiftBy %= 26;

    for (int i = (int)'a'; i <= (int)'z'; i++)
    {
        int toAssign = i + shiftBy;

        if (toAssign < 'a')
        {
            toAssign = 'z' - ('a' - toAssign) + 1;
        }

        if (toAssign > 'z')
        {
            toAssign = 'a' + (toAssign - 'z') - 1;
        }

        translation[(char)i] = toAssign;
    }

    for (int i = (int)'A'; i <= (int)'Z'; i++)
    {
        int toAssign = i + shiftBy;

        if (toAssign < 'A')
        {
            toAssign = 'Z' - ('A' - toAssign) + 1;
        }

        if (toAssign > 'Z')
        {
            toAssign = 'A' + (toAssign - 'Z') - 1;
        }

        translation[(char)i] = toAssign;
    }

    return translation;
}

CaesarCipher::CaesarCipher(int key) : Monoalphabetic(SetTranslation(key)) {}
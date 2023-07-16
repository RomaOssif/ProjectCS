#include "Substitution.hpp"
#include <map>
#include <iostream>
#include <string>

using namespace std;

map<char, char> Substitution::SetTranslation(string key)
{
    map<char, char> translation;

    for (int i = (int)'a', j = 0; i <= (int)'z'; i++, j++)
    {
        translation[(char)i] = tolower(key[j]);
        translation[toupper((char)i)] = toupper(key[j]);
    }

    return translation;
}

Substitution::Substitution(string key) : Monoalphabetic(SetTranslation(key)) {}
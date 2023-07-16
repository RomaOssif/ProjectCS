#include "Monoalphabetic.hpp"
#include <fstream>
#include <string>
#include <map>
#include <iostream>

using namespace std;

Monoalphabetic::Monoalphabetic(map<char, char> translation)
{
    _translation = translation;
}

string Monoalphabetic::Encode(string sentence)
{
    string result = "";

    for (int i = 0; i < sentence.size(); i++)
    {
        if (isalpha(sentence[i]))
            result.push_back(_translation[sentence[i]]);
        else
            result.push_back(sentence[i]);
    }

    return result;
}

string Monoalphabetic::Decode(string sentence)
{
    string result = "";

    for (int i = 0; i < sentence.size(); i++)
    {
        char character = sentence[i];

        if (isalpha(character))
        {
            for (map<char, char>::iterator it = _translation.begin(); it != _translation.end(); it++)
            {
                if (it->second == character)
                    result.push_back(it->first);
            }
        }
        else
            result.push_back(character);
    }

    return result;
}

void Monoalphabetic::EncodeFile(string fileName, string resultFileName)
{
    ifstream file(fileName);
    ofstream result(resultFileName);

    string line;

    while (getline(file, line))
    {
        result << this->Encode(line) << "\n";
    }

    file.close();
    result.close();
}

void Monoalphabetic::DecodeFile(string fileName, string resultFileName)
{
    ifstream file(fileName);
    ofstream result(resultFileName);

    string line;

    while (getline(file, line))
    {
        result << this->Decode(line) << "\n";
    }

    file.close();
    result.close();
}
#include "MorseCode.hpp"
#include <map>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

string MorseCode::EncodeWord(string word)
{
    string encoded = _translation[word[0]];

    for (int i = 1; i < word.size(); i++)
    {
        encoded.append(_letterSpaces);
        encoded.append(_translation[word[i]]);
    }

    return encoded;
}

void MorseCode::CheckInput(string& word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }

        if (!_translation.count(word[i]) && word[i] != ' ')
        {
            word = word.erase(i, 1);
        }
    }
}

string MorseCode::DecodeWord(string word)
{
    vector<string> letters = Split(word, _letterSpaces.size());
    map<char, string>::iterator it;

    string decoded = "";

    for (string letter : letters)
    {
        for (map<char, string>::iterator it = _translation.begin(); it != _translation.end(); it++)
        {
            if (it->second == letter)
            {
                decoded.push_back(it->first);
                break;
            }
        }
    }

    return decoded;
}

string MorseCode::Encode(string sentence)
{
    vector<string> words = Split(sentence, 1);

    for (int i = 0; i < words.size(); i++)
    {
        CheckInput(words[i]);
    }

    string encoded = EncodeWord(words[0]);

    for (int i = 1; i < words.size(); i++)
    {
        encoded.append(_wordSpaces);
        encoded.append(EncodeWord(words[i]));
    }

    return encoded;
}

string MorseCode::Decode(string sentence)
{
    vector<string> words;
    if (sentence.find(_wordSpaces) == std::string::npos)
        words.push_back(sentence);
    else
        words = Split(sentence, _wordSpaces.size());

    string decoded = DecodeWord(words[0]);

    for (int i = 1; i < words.size(); i++)
    {
        decoded.push_back(' ');
        decoded.append(DecodeWord(words[i]));
    }

    return decoded;
}

void MorseCode::EncodeFile(string fileName, string resultFileName)
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

void MorseCode::DecodeFile(string fileName, string resultFileName)
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
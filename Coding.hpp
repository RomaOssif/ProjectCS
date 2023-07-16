#ifndef CODING_HPP
#define CODING_HPP

#include <iostream>
#include <vector>

using namespace std;

class Coding
{
protected:
    vector<string> Split(string input, int lengthOfSpaces)
    {
        string spaces = "";
        for (int i = 0; i < lengthOfSpaces; i++)
        {
            spaces.push_back(' ');
        }

        string temp = "";
        vector<string> subStrings;

        while (input.find(spaces) != std::string::npos)
        {
            for (int i = 0, stopAt = input.find(spaces); i < stopAt; i++)
            {
                temp.push_back(input[i]);
            }

            input = input.erase(0, temp.size() + lengthOfSpaces);

            subStrings.push_back(temp);

            temp.erase();
        }

        subStrings.push_back(input);

        return subStrings;
    }

public:
    virtual string Encode(string) = 0;
    virtual string Decode(string) = 0;

    virtual void EncodeFile(string, string) = 0;
    virtual void DecodeFile(string, string) = 0;
};

#endif //CODING_HPP
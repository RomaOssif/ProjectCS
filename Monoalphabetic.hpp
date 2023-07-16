#ifndef MONOALPHABETIC_HPP
#define MONOALPHABETIC_HPP

#include "Coding.hpp"
#include <map>
#include <iostream>

using namespace std;

class Monoalphabetic : public Coding
{
protected:
    map<char, char> _translation;

public:
    Monoalphabetic(map<char, char>);

    string Encode(string) override;
    string Decode(string) override;

    void EncodeFile(string, string) override;
    void DecodeFile(string, string) override;
};

#endif //MONOALPHABETIC_HPP
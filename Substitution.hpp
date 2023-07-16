#ifndef SUBSTITUTION_HPP
#define SUBSTITUTION_HPP

#include "Monoalphabetic.hpp"
#include <map>
#include <iostream>

using namespace std;

class Substitution : public Monoalphabetic
{
private:
    map<char, char> SetTranslation(string);

public:
    Substitution(string);
};

#endif //SUBSTITUTION_HPP
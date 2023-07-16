#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include "Monoalphabetic.hpp"
#include <map>
#include <iostream>

using namespace std;

class CaesarCipher : public Monoalphabetic
{
private:
    map<char, char> SetTranslation(int);

public:
    CaesarCipher(int);
};

#endif //CAESARCIPHER_HPP
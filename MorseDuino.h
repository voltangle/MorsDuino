#ifndef MORZEDUINO_H
#define MORZEDUINO_H

#include <string>
#include "Arduino.h"

class MorzeDuino {
    public:
        int MorseDuino(int pin);
        void displayText(std::string text);
        void displayInt(int number);
        void displayChar(char character);
};

#endif // MORZEDUINO_H
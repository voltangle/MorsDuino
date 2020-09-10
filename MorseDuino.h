#ifndef MORSEDUINO_H
#define MORSEDUINO_H

#include <string>
#include "Arduino.h"

class MorseDuino {
    public:
        MorseDuino(int pin = 13);
        void displayText(std::string text);
        void displayInt(int number);
        void displayChar(char character);
    private:
        int _pin = pin;
};

#endif // MORSEDUINO_H
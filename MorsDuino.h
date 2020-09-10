#ifndef MORSDUINO_H
#define MORSDUINO_H

#include <string>
#include "Arduino.h"

class MorsDuino {
    public:
        MorsDuino(int pin = 13);
        void displayText(std::string text);
        void displayInt(int number);
        void displayChar(char character);
    private:
        int _pin = pin;
        void showDot();
        void showDash();
};

#endif // MORSDUINO_H
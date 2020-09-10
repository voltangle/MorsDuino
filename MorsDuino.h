#ifndef MORSDUINO_H
#define MORSDUINO_H

#include "Arduino.h"

class MorsDuino {
    public:
        MorsDuino(int pin = 13);
        void displayText(String text);
        void displayInt(int number);
        void displayChar(char character);
    private:
        int _pin = 13;
        void _dot(int count = 1);
        void _dash(int count = 1);
        void _delaySeparator(int type);
};

#endif // MORSDUINO_H
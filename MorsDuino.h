#ifndef MORSDUINO_H
#define MORSDUINO_H

#include "Arduino.h"

class MorsDuino {
    public:
        MorsDuino(int pin);
        void displayString(String text);
        void displayChar(char character);
    private:
        int _pin;
        int _letterSeparatorDelay;
        int _wordSeparatorDelay;
        void _dot(int count = 1);
        void _dash(int count = 1);
        void _delaySeparator(int type);
};

#endif // MORSDUINO_H
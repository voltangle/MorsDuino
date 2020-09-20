#ifndef MORSDUINO_H
#define MORSDUINO_H

#include "Arduino.h"

class MorsDuino {
   public:
    class Led {
       public:
        Led(int pin);
        void displayString(String text);
        void displayChar(char character);
        void displayInt(int number);

       private:
        int _pin;
        int _letterSeparatorDelay;
        int _wordSeparatorDelay;
        void _dot(int count);
        void _dash(int count);
        void _delaySeparator(int type);
    };
    class RgbLed {
       public:
        RgbLed(int red, int green, int blue);
        void displayString(char color, String text);
        void displayInt(char color, int number);
        void displayChar(char color, char character);

       private:
        int _redPin;
        int _greenPin;
        int _letterSeparatorDelay;
        int _wordSeparatorDelay;
        void _dot(int count);
        void _dash(int count);
        void _delaySeparator(int type);
    };
};

#endif  // MORSDUINO_H
#include "Arduino.h"
#include "MorsDuino.h"

MorsDuino::Led Led(int pin = 13)
{
    pinMode(pin, OUTPUT);
    MorsDuino::Led _letterSeparatorDelay = 400;
    MorsDuino::Led _wordSeparatorDelay = 1000;
    MorsDuino::Led _pin = pin;
}
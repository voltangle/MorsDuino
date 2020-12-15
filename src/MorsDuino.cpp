#include "MorsDuino.h"

#include "Arduino.h"

MorsDuinoLed::MorsDuinoLed(int pin = 13) {
    pinMode(pin, OUTPUT);
    _letterSeparatorDelay = 400;
    _wordSeparatorDelay = 1000;
    _pin = pin;
}

MorsDuinoRgbLed::MorsDuinoRgbLed(int red, int green, int blue, int type) {
    // Setup pins
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    // Setup local variables
    _redPin = red;
    _greenPin = green;
    _bluePin = blue;
}
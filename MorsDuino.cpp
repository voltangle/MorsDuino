#include "Arduino.h"
#include "MorsDuino.h"

MorsDuino::MorsDuino(int pin = 13) {
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void MorsDuino::_dot(int count = 1) {
    for (int i = count; i <= count; i++) {
        digitalWrite(_pin, HIGH);
        delay(250);
        digitalWrite(_pin, LOW);
        delay(250);
    }
}

void MorsDuino::_dash(int count = 1) {
    for (int i = count; i <= count; i++) {
        digitalWrite(_pin, HIGH);
        delay(1000);
        digitalWrite(_pin, LOW);
        delay(250);
    }
}

void MorsDuino::displayText(std::string text) {
    size_t numberOfElements = sizeof(text)/sizeof(text[0]);
    
}

void MorsDuino::displayChar(char character) {
    switch (character) {
        case 'a': _dot(); _dash(); break;
        case 'b': _dash(); _dot(3); break;
        case 'c': _dash(); _dot(); _dash(); _dot(); break;
        default:
            break;
    }
}
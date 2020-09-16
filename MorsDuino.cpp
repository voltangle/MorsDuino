#include "Arduino.h"
#include "MorsDuino.h"
//#include "microLED.h"

MorsDuino::MorsDuino(int pin = 13, int device = 1) {
    if (device == 1) {
        pinMode(pin, OUTPUT);
    } else if (device == 2) {

    }
    _letterSeparatorDelay = 400;
    _wordSeparatorDelay = 1000;
    _pin = pin;
}

void MorsDuino::_dot(int count = 1) {
    int num = 1;
    do {
        digitalWrite(_pin, HIGH);
        delay(125);
        digitalWrite(_pin, LOW);
        delay(125);
        num++;
    } while (num <= count);
}

void MorsDuino::_dash(int count = 1) {
    int num = 1;
    do {
        digitalWrite(_pin, HIGH);
        delay(500);
        digitalWrite(_pin, LOW);
        delay(125);
        num++;
    } while (num <= count);
}

void MorsDuino::_delaySeparator(int type) {
    if (type == 1) {
        delay(_letterSeparatorDelay);
    } else if (type == 2) {
        delay(_wordSeparatorDelay);
    }
}

void MorsDuino::displayString(String text) {
    size_t numberOfElements = sizeof(text)/sizeof(text[0]);
    for (int i = 0; i <= numberOfElements; i++)
    {
        MorsDuino::displayChar(text[i]);
    }
}

void MorsDuino::displayChar(char character) {
    switch (character) {
        // Numbers
        case '1': _dot(); _dash(4); _delaySeparator(1); break;
        case '2': _dot(2); _dash(3); _delaySeparator(1); break;
        case '3': _dot(3); _dash(2); _delaySeparator(1); break;
        case '4': _dot(4); _dash(1); _delaySeparator(1); break;
        case '5': _dot(5); _delaySeparator(1); break;
        case '6': _dash(1); _dot(4); _delaySeparator(1); break;
        case '7': _dash(2); _dot(3); _delaySeparator(1); break;
        case '8': _dash(3); _dot(2); _delaySeparator(1); break;
        case '9': _dash(4); _dot(1); _delaySeparator(1); break;
        case '0': _dash(5); _delaySeparator(1); break;
        // English alphabet
        case 'a': _dot(); _dash(); _delaySeparator(1); break;
        case 'b': _dash(); _dot(3); _delaySeparator(1); break;
        case 'c': _dash(); _dot(); _dash(); _dot(); _delaySeparator(1); break;
        case 'd': _dash(); _dot(2); _delaySeparator(1); break;
        case 'e': _dot(); _delaySeparator(1); break;
        case 'f': _dot(2); _dash(); _dot(); _delaySeparator(1); break;
        case 'g': _dash(2); _dot(); _delaySeparator(1); break;
        case 'h': _dot(4); _delaySeparator(1); break;
        case 'i': _dot(2); _delaySeparator(1); break;
        case 'j': _dot(); _dash(3); _delaySeparator(1); break;
        case 'k': _dash(); _dot(); _dash(); _delaySeparator(1); break;
        case 'l': _dot(); _dash(); _dot(2); _delaySeparator(1); break;
        case 'm': _dash(2); _delaySeparator(1); break;
        case 'n': _dash(); _dot(); _delaySeparator(1); break;
        case 'o': _dash(3); _delaySeparator(1); break;
        case 'p': _dot(); _dash(2); _dot(); _delaySeparator(1); break;
        case 'q': _dash(2); _dot(); _dash(); _delaySeparator(1); break;
        case 'r': _dot(); _dash(); _dot(); _delaySeparator(1); break;
        case 's': _dot(3); _delaySeparator(1); break;
        case 't': _dash(); _delaySeparator(1); break;
        case 'u': _dot(2); _dash(); _delaySeparator(1); break;
        case 'v': _dot(3); _dash(); _delaySeparator(1); break;
        case 'w': _dot(); _dash(2); _delaySeparator(1); break;
        case 'x': _dash(); _dot(2); _dash(); _delaySeparator(1); break;
        case 'y': _dash(); _dot(); _dash(2); _delaySeparator(1); break;
        case 'z': _dash(2); _dot(2); _delaySeparator(1); break;
        case ' ': _delaySeparator(2); break;
        default:
            break;
    }
}

void MorsDuino::displayInt(int number) {
    String numbers = String(number);
    size_t numberOfElements = sizeof(numbers)/sizeof(numbers[0]);
    for (int i = 0; i <= numberOfElements; i++)
    {
        MorsDuino::displayChar(numbers[i]);
    }
}
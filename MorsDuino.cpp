#include "Arduino.h"
#include "MorsDuino.h"

MorsDuino::MorsDuino(int pin = 13) {
    pinMode(pin, OUTPUT);
    _pin = pin;
}
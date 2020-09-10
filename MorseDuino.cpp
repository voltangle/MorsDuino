#include "Arduino.h"
#include "MorseDuino.h"

MorseDuino::MorseDuino(int pin = 13) {
    pinMode(pin, OUTPUT);

}
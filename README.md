# MorseDuino

An Arduino Library for generating Morse code on LEDs. Every Arduino board is supported(library uses standart Wiring functions)

## Usage

``` C++
#include "MorseDuino.h"

void setup() {
    MorseDuino morsePin(6); // If you don't specify the pin, it will be defaulted to 13
}

void loop() {
    morsePin.displayText("SOS"); // Display SOS morse code on LED hooked up to 6 pin
}
```

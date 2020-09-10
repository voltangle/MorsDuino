# MorseDuino

An Arduino Library for generating Morse code on LEDs. Every Arduino board is supported(library uses standart Wiring functions)

## Usage

``` C++
#include "MorsDuino.h"

MorsDuino led(13); // Make new instance of MarsDuino class with name 'led'

void setup() {
  Serial.begin(9600); // Start serial on 9600 baud rate
}

void loop() {
  while(!Serial.available()); // Wait until serial has some data
  char data = Serial.read(); // Read data
  led.displayChar(data); // Draw morse on 13 LED
}
```

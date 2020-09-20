# MorseDuino

The lightweight Arduino Library for generating Morse code on LEDs, light strips, and speakers. Every Arduino board is supported(library uses standart Wiring functions).

## What it can do

## Usage

``` C++
#include "MorsDuino.h"

MorsDuinoLed led(13); // Make new instance of MarsDuinoLed class with name 'led'

void setup() {
  Serial.begin(9600); // Start serial on 9600 baud rate
}

void loop() {
  while(!Serial.available()); // Wait until serial has some data
  char data = Serial.read(); // Read data
  led.displayChar(data); // Draw morse on 13 LED
}
```

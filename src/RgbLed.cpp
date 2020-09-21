#include "Arduino.h"
#include "MorsDuino.h"

void MorsDuinoRgbLed::setColor(char color) {
    _drawColor(color);
    _savedColor = color;
}

void MorsDuinoRgbLed::setState(bool state) {
    if (state) {
        analogWrite(_redPin, _redColorBuffer);
        analogWrite(_greenPin, _greenColorBuffer);
        analogWrite(_bluePin, _blueColorBuffer);
    } else {
        analogWrite(_redPin, 0);
        analogWrite(_greenPin, 0);
        analogWrite(_bluePin, 0);
    }
}

// Function to display color
void MorsDuinoRgbLed::_drawColor(char color) {
    int redColor = ((color >> 16) & 0xFF) / 255.0;   // Extract the RR byte
    int greenColor = ((color >> 8) & 0xFF) / 255.0;  // Extract the GG byte
    int blueColor = ((color)&0xFF) / 255.0;          // Extract the BB byte

    // Save colors
    _redColorBuffer = redColor;
    _greenColorBuffer = greenColor;
    _blueColorBuffer = blueColor;

    analogWrite(_redPin, redColor);
    analogWrite(_greenPin, greenColor);
    analogWrite(_bluePin, blueColor);
}

void MorsDuinoRgbLed::_off() {
    analogWrite(_redPin, 0);
    analogWrite(_greenPin, 0);
    analogWrite(_bluePin, 0);
}
void MorsDuinoRgbLed::_dot(int count = 1) {
    int num = 1;
    do {
        _drawColor(_savedColor);
        delay(125);
        _off();
        delay(125);
        num++;
    } while (num <= count);
}
void MorsDuinoRgbLed::_dash(int count = 1) {
    int num = 1;
    do {
        _drawColor(_savedColor);
        delay(500);
        _off();
        delay(125);
        num++;
    } while (num <= count);
}

void MorsDuinoRgbLed::_delaySeparator(int type) {
    if (type == 1) {
        delay(_letterSeparatorDelay);
    } else if (type == 2) {
        delay(_wordSeparatorDelay);
    }
}

void MorsDuinoRgbLed::displayString(String text) {
    size_t numberOfElements = sizeof(text) / sizeof(text[0]);
    for (int i = 0; i <= numberOfElements; i++) {
        MorsDuinoRgbLed::displayChar(text[i]);
    }
}

void MorsDuinoRgbLed::displayChar(char character) {
    switch (character) {
        // Numbers
        case '1':
            _dot();
            _dash(4);
            _delaySeparator(1);
            break;
        case '2':
            _dot(2);
            _dash(3);
            _delaySeparator(1);
            break;
        case '3':
            _dot(3);
            _dash(2);
            _delaySeparator(1);
            break;
        case '4':
            _dot(4);
            _dash(1);
            _delaySeparator(1);
            break;
        case '5':
            _dot(5);
            _delaySeparator(1);
            break;
        case '6':
            _dash(1);
            _dot(4);
            _delaySeparator(1);
            break;
        case '7':
            _dash(2);
            _dot(3);
            _delaySeparator(1);
            break;
        case '8':
            _dash(3);
            _dot(2);
            _delaySeparator(1);
            break;
        case '9':
            _dash(4);
            _dot(1);
            _delaySeparator(1);
            break;
        case '0':
            _dash(5);
            _delaySeparator(1);
            break;
        // English alphabet
        case 'a':
            _dot();
            _dash();
            _delaySeparator(1);
            break;
        case 'b':
            _dash();
            _dot(3);
            _delaySeparator(1);
            break;
        case 'c':
            _dash();
            _dot();
            _dash();
            _dot();
            _delaySeparator(1);
            break;
        case 'd':
            _dash();
            _dot(2);
            _delaySeparator(1);
            break;
        case 'e':
            _dot();
            _delaySeparator(1);
            break;
        case 'f':
            _dot(2);
            _dash();
            _dot();
            _delaySeparator(1);
            break;
        case 'g':
            _dash(2);
            _dot();
            _delaySeparator(1);
            break;
        case 'h':
            _dot(4);
            _delaySeparator(1);
            break;
        case 'i':
            _dot(2);
            _delaySeparator(1);
            break;
        case 'j':
            _dot();
            _dash(3);
            _delaySeparator(1);
            break;
        case 'k':
            _dash();
            _dot();
            _dash();
            _delaySeparator(1);
            break;
        case 'l':
            _dot();
            _dash();
            _dot(2);
            _delaySeparator(1);
            break;
        case 'm':
            _dash(2);
            _delaySeparator(1);
            break;
        case 'n':
            _dash();
            _dot();
            _delaySeparator(1);
            break;
        case 'o':
            _dash(3);
            _delaySeparator(1);
            break;
        case 'p':
            _dot();
            _dash(2);
            _dot();
            _delaySeparator(1);
            break;
        case 'q':
            _dash(2);
            _dot();
            _dash();
            _delaySeparator(1);
            break;
        case 'r':
            _dot();
            _dash();
            _dot();
            _delaySeparator(1);
            break;
        case 's':
            _dot(3);
            _delaySeparator(1);
            break;
        case 't':
            _dash();
            _delaySeparator(1);
            break;
        case 'u':
            _dot(2);
            _dash();
            _delaySeparator(1);
            break;
        case 'v':
            _dot(3);
            _dash();
            _delaySeparator(1);
            break;
        case 'w':
            _dot();
            _dash(2);
            _delaySeparator(1);
            break;
        case 'x':
            _dash();
            _dot(2);
            _dash();
            _delaySeparator(1);
            break;
        case 'y':
            _dash();
            _dot();
            _dash(2);
            _delaySeparator(1);
            break;
        case 'z':
            _dash(2);
            _dot(2);
            _delaySeparator(1);
            break;
        case ' ':
            _delaySeparator(2);
            break;
        default:
            break;
    }
}

void MorsDuinoRgbLed::displayInt(int number) {
    String numbers = String(number);
    size_t numberOfElements = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i <= numberOfElements; i++) {
        MorsDuinoRgbLed::displayChar(numbers[i]);
    }
}

void MorsDuinoRgbLed::setBrightness(int brightness) {
    // Extract data
    int redColor = ((_savedColor >> 16) & 0xFF) / 255.0;   // Extract the RR byte
    int greenColor = ((_savedColor >> 8) & 0xFF) / 255.0;  // Extract the GG byte
    int blueColor = ((_savedColor)&0xFF) / 255.0;          // Extract the BB byte

    // Save data
    _redPinMaxBrightnessBuffer = redColor;

    // Set brightness using percents. Just get a percent value from variables :)
    analogWrite(_redPin, redColor % brightness);
    analogWrite(_greenPin, greenColor % brightness);
    analogWrite(_bluePin, blueColor % brightness);
}
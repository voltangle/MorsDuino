#ifndef MORSDUINO_H
#define MORSDUINO_H

#include "Arduino.h"

class MorsDuinoLed {
   public:
    MorsDuinoLed(int pin);
    void displayString(String text);
    void displayChar(char character);
    void displayInt(int number);

   private:
    int _pin;
    int _letterSeparatorDelay;
    int _wordSeparatorDelay;
    void _dot(int count);
    void _dash(int count);
    void _delaySeparator(int type);
};
class MorsDuinoRgbLed {
   public:
    MorsDuinoRgbLed(int red, int green, int blue);

    void displayString(String text);
    void displayInt(int number);
    void displayChar(char character);

    void setColor(char color);
    void setBrightness(int brightness);
    void setState(bool state);

   private:
    int _redPin;
    int _greenPin;
    int _bluePin;

    int _redColorBuffer;
    int _greenColorBuffer;
    int _blueColorBuffer;

    int _letterSeparatorDelay;
    int _wordSeparatorDelay;

    char _savedColor;

    int _redPinMaxBrightnessBuffer;
    int _greenPinMaxBrightnessBuffer;
    int _bluePinMaxBrightnessBuffer;

    void _dot(int count);
    void _dash(int count);
    void _delaySeparator(int type);
    void _changeState(bool state);
    void _applyBrightnessSettings();
    void _drawColor(char color);
    void _off();
};

#endif  // MORSDUINO_H
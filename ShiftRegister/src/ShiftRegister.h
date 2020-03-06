#ifndef ShiftRegister
#define ShiftRegister

#include <Arduino.h>

class sr{
  public:
    sr(int dataPin,int latchPin, int clockPin);
    void setPin(int pin, bool pin_status);
    void setAllPins(int pins);
    void setAllTo(bool status);
    int getPinValue(int pin);
  private:
    int _dataPin, _latchPin, _clockPin;
    bool _pin[8] = {0,0,0,0,0,0,0,0};
};


#endif

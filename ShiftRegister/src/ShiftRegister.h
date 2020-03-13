#ifndef ShiftRegister
#define ShiftRegister

#include <Arduino.h>

class sr{
  public:
    sr(byte dataPin,byte latchPin, byte clockPin, byte numSr);
    void setPin(byte pin, bool pin_status);
    void setAllPins(unsigned long pins);
    void setAllTo(bool status);
    byte getPinValue(byte pin);
	void invertPin(byte pin);
  private:
    byte _dataPin, _latchPin, _clockPin, _numSr;
    bool _pin[40];
	void doShiftOut(unsigned long pin);
};


#endif

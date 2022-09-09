#ifndef ShiftRegister
#define ShiftRegister

#include <Arduino.h>

class sr{
  public:
    sr(byte dataPin,byte latchPin, byte clockPin, byte oePin = NULL, byte numSr = 1);
    //sr(byte dataPin,byte latchPin, byte clockPin);
	void initialize();
    int setPin(byte pin, bool pin_status);
    void setAllPins(unsigned long pins);
    void setAllTo(bool status);
    const bool getPinValue(byte pin);
	void invertPin(byte pin);
    void setBitOrder(byte bitOrder);
	void setBrightness(byte brightness);
	
  private:
    const byte _dataPin, _latchPin, _clockPin, _oePin;
	byte _bitOrder, _numSr;
    bool _pin[40];
	void doShiftOut(unsigned long pin);
};

#endif

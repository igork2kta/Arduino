#include <ShiftRegister.h>

sr::sr(byte dataPin, byte latchPin, byte clockPin, byte numSr){
  _dataPin = dataPin;
  _latchPin = latchPin;
  _clockPin = clockPin;
  _numSr = numSr;
  pinMode(_dataPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  for(byte i = 0; i < (8 * numSr); i++){
	  _pin[i] = LOW;
  }
}

void sr::setPin(byte pin, bool pin_status){
  unsigned long state = 0, bin = 1;
  if (pin_status == HIGH)
    _pin[pin] = 1;
  else
    _pin[pin] = 0;
    
    for(int i = 0; i < (8* _numSr); i++){
            if(_pin[i] == 1)
              state+= bin; 
           
            bin += bin;
	}
	doShiftOut(state);
}

void sr::setAllPins(unsigned long pins){
	String pinState = String(pins,BIN);
	
	for(int i = 0; i < (8*_numSr); i++){
		if(pinState[i] == '1')
			_pin[i] = HIGH;
		else	
			_pin[i] = LOW;

	}
	doShiftOut(pins); 
}


void sr::setAllTo(bool state){
	if(state == LOW){	
		doShiftOut(0);
		for(int i = 0; i < (8*_numSr); i++)
			_pin[i] = LOW;
	}
	else if(state == HIGH){      
		unsigned long all = pow(2,(_numSr * 8));
		doShiftOut(all); 
		for(int i = 0; i < (8*_numSr); i++)
			_pin[i] = HIGH;
	}
}

byte sr::getPinValue(byte pin){
	return _pin[pin];
}

void sr::doShiftOut(unsigned long pin){
	shiftOut(_dataPin, _clockPin, LSBFIRST, 0);
	shiftOut(_dataPin, _clockPin, LSBFIRST, (0 >> 8));
	digitalWrite(_latchPin, LOW);
    digitalWrite(_latchPin, HIGH);
	delay(20);
    shiftOut(_dataPin, _clockPin, LSBFIRST, pin);
	shiftOut(_dataPin, _clockPin, LSBFIRST, (pin >> 8));
	digitalWrite(_latchPin, LOW);
    digitalWrite(_latchPin, HIGH);
}

void sr::invertPin(byte pin){
  _pin[pin] = !(_pin[pin]);
  unsigned long state = 0, bin = 1;

    for(int i = 0; i < (8* _numSr); i++){
            if(_pin[i] == 1)
              state+= bin; 
           
            bin += bin;
	}
	doShiftOut(state);
}
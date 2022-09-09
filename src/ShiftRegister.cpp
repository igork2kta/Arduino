#include <ShiftRegister.h>

sr::sr(byte dataPin, byte latchPin, byte clockPin, byte oePin = NULL, byte numSr = 1) : 
	_dataPin(dataPin), _latchPin(latchPin), _clockPin(clockPin), _oePin(oePin), _numSr(numSr)
{
  initialize();
}

void sr::initialize(){
  pinMode(_dataPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  _bitOrder = LSBFIRST;
  for(byte i = 0; i < (8 * _numSr); i++){
	  _pin[i] = LOW;
  }
}

int sr::setPin(byte pin, bool pin_status){
  unsigned long state = 0, bin = 1;
  _pin[pin] = pin_status;

    for(int i = 0; i < (8* _numSr); i++){
            if(_pin[i] == 1)// == 1
              state+= bin; 
           
            bin += bin;
	}
	doShiftOut(state);
	
	return state;
}

void sr::setAllPins(unsigned long pins){
	String pinState = String(pins,BIN);
	
	for(int i = 0; i < (8*_numSr); i++){
		if(pinState[i])
			_pin[i] = HIGH;
		else	
			_pin[i] = LOW;
	}
	doShiftOut(pins); 
}


void sr::setAllTo(bool state){
	
	if(state){ //== HIGH  
		unsigned long all = pow(2,(_numSr * 8));
		doShiftOut(all); 
		for(int i = 0; i < (8*_numSr); i++)
			_pin[i] = HIGH;
	}
	else{ //if(state == LOW){	
		doShiftOut(0);
		for(int i = 0; i < (8*_numSr); i++)
			_pin[i] = LOW;
	}
}

const bool sr::getPinValue(byte pin){
	return _pin[pin];
}

void sr::doShiftOut(unsigned long pin){
	shiftOut(_dataPin, _clockPin, _bitOrder, 0);
	if(_numSr > 1)	shiftOut(_dataPin, _clockPin, _bitOrder, (0 >> 8));
	digitalWrite(_latchPin, LOW);
    //digitalWrite(_latchPin, HIGH);
	delay(20);
    shiftOut(_dataPin, _clockPin, _bitOrder, pin);
	if(_numSr > 1) shiftOut(_dataPin, _clockPin, _bitOrder, (pin >> 8));
	//digitalWrite(_latchPin, LOW);
    digitalWrite(_latchPin, HIGH);
}

void sr::invertPin(byte pin){
  setPin(pin,!(_pin[pin]));
}

void sr::setBitOrder(byte bitOrder) {
	_bitOrder = bitOrder;
}

void sr::setBrightness(byte brightness) // 0 to 255
{
	if(_oePin != NULL)
		analogWrite(_oePin, 255-brightness);
}
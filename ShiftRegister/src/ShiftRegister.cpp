#include <ShiftRegister.h>

sr::sr(int dataPin, int latchPin, int clockPin){
  _dataPin = dataPin;
  _latchPin = latchPin;
  _clockPin = clockPin;
  
  pinMode(_dataPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);

}

void sr::setPin(int pin, bool pin_status){
  int state = 0, bin = 1;
  if (pin_status == HIGH)
    _pin[pin] = 1;
  else
    _pin[pin] = 0;
    
    for(int i = 0; i<8; i++){
            if(_pin[i] == 1)
              state+= bin; 
           
            bin += bin;
	Serial.println(_pin[i]);
        }
          //Comunicação com o CI
	  
          shiftOut(_dataPin, _clockPin, MSBFIRST, 0);
	  digitalWrite(_latchPin, LOW);
          digitalWrite(_latchPin, HIGH);
	  delay(30);
          
          shiftOut(_dataPin, _clockPin, MSBFIRST, state);
	  digitalWrite(_latchPin, LOW);
          digitalWrite(_latchPin, HIGH); 
}

void sr::setAllPins(int pins){
	  shiftOut(_dataPin, _clockPin, MSBFIRST, 0);
	  digitalWrite(_latchPin, LOW);
          digitalWrite(_latchPin, HIGH);
	  delay(30);
          
          shiftOut(_dataPin, _clockPin, MSBFIRST, pins);
	  digitalWrite(_latchPin, LOW);
          digitalWrite(_latchPin, HIGH); 

}


void sr::setAllTo(bool state){
	  shiftOut(_dataPin, _clockPin, MSBFIRST, 0);
	  digitalWrite(_latchPin, LOW);
          digitalWrite(_latchPin, HIGH);
	  delay(30);	
	
	if(state == HIGH){      
          shiftOut(_dataPin, _clockPin, MSBFIRST, 255);
	  digitalWrite(_latchPin, LOW);
          digitalWrite(_latchPin, HIGH); 
	}
}

int sr::getPinValue(int pin){
	
return _pin[pin];
}
/*Autor Igor Pinheiro da Silva 10/03/2020 */

#include <ShiftRegister.h>

//Alterar para os pinos de preferência
const int dataPin = 2;
const int latchPin = 3;
const int clockPin = 4;

//Criação de um objeto do tipo sr(ShiftRegister)
sr shiftregister(dataPin,latchPin,clockPin);

void setup() {
 Serial.begin(9600); 
}

void loop() {
  if(Serial.available()){
    String pin = Serial.readStringUntil("\n");
    shiftregister.invertPin(pin.toInt());

  }
}
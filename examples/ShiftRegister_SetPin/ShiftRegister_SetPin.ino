/*Autor Igor Pinheiro da Silva 10/03/2020 */

#include <ShiftRegister.h>

//Alterar para os pinos de preferência
const int dataPin = 2;
const int latchPin = 3;
const int clockPin = 4;

//Criação de um opjeto do tipo sr(ShiftRegister)
sr shiftregister(dataPin,latchPin,clockPin);

void setup() {
  
  shiftregister.setPin(0,LOW);
  shiftregister.setPin(1,HIGH);
  shiftregister.setPin(2,LOW);
  shiftregister.setPin(3,HIGH);
  shiftregister.setPin(4,LOW);
  shiftregister.setPin(5,HIGH);
  shiftregister.setPin(6,LOW);
  shiftregister.setPin(7,HIGH);
}

void loop() {

 
}

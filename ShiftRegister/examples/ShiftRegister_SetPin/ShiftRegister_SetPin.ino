/*Autor Igor Pinheiro da Silva*/
#include <ShiftRegister.h>

//Criação de um opjeto do tipo sr(ShiftRegister)
//Ordem dos pinos dataPin/latchPin/clockPin
sr shiftregister(2,3,4);

void setup() {
  //Defineo estado dos pinos
  shiftregister.setPin(1, HIGH);
  shiftregister.setPin(3, HIGH);
  shiftregister.setPin(5, HIGH);
  shiftregister.setPin(7, HIGH);
  shiftregister.setPin(0, LOW);
  shiftregister.setPin(2, LOW);
  shiftregister.setPin(4, LOW);
  shiftregister.setPin(6, LOW);
}

void loop() {
 
 
}

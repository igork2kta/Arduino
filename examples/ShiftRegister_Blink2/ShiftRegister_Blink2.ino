/*Autor Igor Pinheiro da Silva 10/03/2020 */

#include <ShiftRegister.h>

//Alterar para os pinos de preferência
const int dataPin = 2;
const int latchPin = 3;
const int clockPin = 4;

//Criação de um objeto do tipo sr(ShiftRegister)
sr shiftregister(dataPin,latchPin,clockPin);

void setup() {
}

void loop() {
  //Ativa todos os Pinos
  shiftregister.setAllTo(HIGH);
  delay(1000);
  //Desativa todos os Pinos
  shiftregister.setAllTo(LOW);
  delay(1000);
 
}

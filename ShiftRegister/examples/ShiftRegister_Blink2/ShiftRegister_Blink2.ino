/*Autor Igor Pinheiro da Silva*/
#include <ShiftRegister.h>

//Criação de um opjeto do tipo sr(ShiftRegister)
//Ordem dos pinos dataPin/latchPin/clockPin
sr shiftregister(2,3,4);

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

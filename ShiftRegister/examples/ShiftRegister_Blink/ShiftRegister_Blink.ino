/*Autor Igor Pinheiro da Silva*/
#include <ShiftRegister.h>

//Criação de um opjeto do tipo sr(ShiftRegister)
//Ordem dos pinos dataPin/latchPin/clockPin
sr shiftregister(2,3,4);

void setup() {
  
}

void loop() {
   //Acende um LED de cada vez a cada 1 segundo
   for(int i = 0; i < 8; i++){
    shiftregister.setPin(i, HIGH);
    delay(1000);
   }
   //Apaga um LED a cada vez a cada 1 segundo
   for(int j = 7; j >= 0; j--){
    shiftregister.setPin(j, LOW);
    delay(1000);
   }
 
}

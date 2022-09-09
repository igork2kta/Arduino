/*Autor Igor Pinheiro da Silva 10/03/2020 */

#include <ShiftRegister.h>

//Alterar para os pinos de preferência
const int dataPin = 2;
const int latchPin = 3;
const int clockPin = 4;
const int numOfSr = 1; // Número de shift registers no circuito

//Criação de um objeto do tipo sr(ShiftRegister)
sr shiftregister(dataPin,latchPin,clockPin, NULL, numOfSr);

void setup() {
}

void loop() {
   //Acende um LED de cada vez a cada 1 segundo
   for(int i = 0; i < (numOfSr * 8); i++){
    shiftregister.setPin(i, HIGH);
    delay(1000);
   }
   //Apaga um LED a cada vez a cada 1 segundo
   for(int j = (numOfSr * 8)-1; j >= 0; j--){
    shiftregister.setPin(j, LOW);
    delay(1000);
   }
 
}

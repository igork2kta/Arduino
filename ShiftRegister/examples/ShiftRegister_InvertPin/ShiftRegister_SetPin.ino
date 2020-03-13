/*Autor Igor Pinheiro da Silva 10/03/2020 */

#include <ShiftRegister.h>

//Alterar para os pinos de preferência
const int dataPin = 2;
const int latchPin = 3;
const int clockPin = 4;
const int numOfSr = 2; // Número de shift registers no circuito

//Criação de um opjeto do tipo sr(ShiftRegister)
sr shiftregister(dataPin,latchPin,clockPin,numOfSr);

void setup() {
 Serial.begin(9600); 
}

void loop() {
  if(Serial.available()){
    String pin = Serial.readStringUntil("\n");
    shiftregister.invert8
    Pin(pin.toInt());
    
  }
 
}

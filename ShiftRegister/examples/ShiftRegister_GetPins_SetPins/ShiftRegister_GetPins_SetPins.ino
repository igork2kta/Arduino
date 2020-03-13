/*Autor Igor Pinheiro da Silva 10/03/2020 */

#include <ShiftRegister.h>

//Alterar para os pinos de preferência
const int dataPin = 2;
const int latchPin = 3;
const int clockPin = 4;
const int numOfSr = 1; // Número de shift registers no circuito
//Criação de um opjeto do tipo sr(ShiftRegister)

sr shiftregister(dataPin,latchPin,clockPin,numOfSr);
void setup() {
  Serial.begin(9600);

  //Basicamente é o comando ShiftOut, pode ser um número binário ou inteiro de 8 bits
  shiftregister.setAllPins(0b1010101010101010);

  //Imprime na porta serial o valor de cada pino
  for(int i = 0; i < (numOfSr * 8); i++){
    int value = shiftregister.getPinValue(i);
    Serial.print(value);
    delay(500);
  }
}

void loop() {

  
  
 
}

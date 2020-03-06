/*Autor Igor Pinheiro da Silva*/
#include <ShiftRegister.h>

//Criação de um opjeto do tipo sr(ShiftRegister)
//Ordem dos pinos dataPin/latchPin/clockPin
sr shiftregister(2,3,4);

void setup() {
  Serial.begin(9600);

  //Basicamente é o comando ShiftOut, pode ser um número binário ou inteiro de 8 bits
  shiftregister.setAllPins(0b10101010);

  //Imprime na porta serial o valor de cada pino
  for(int i; i < 8; i++){
    int value = shiftregister.getPinValue(i);
    Serial.print(value);
    delay(500);
  }
}

void loop() {

  
  
 
}

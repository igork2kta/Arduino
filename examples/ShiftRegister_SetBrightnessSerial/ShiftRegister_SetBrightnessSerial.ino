/*Autor Igor Pinheiro da Silva 09/09/2022 */

#include <ShiftRegister.h>
String brightness;

//Alterar para os pinos de preferência
const byte dataPin = 2;
const byte latchPin = 3;
const byte clockPin = 4;
const byte oePin = 5; //Precisa ser PWM
const byte numOfSr = 1; // Número de shift registers no circuito

//Criação de um objeto do tipo sr(ShiftRegister)
sr shiftregister(dataPin,latchPin,clockPin, oePin, numOfSr);

void setup() {
  shiftregister.setBrightness(255);
  shiftregister.setAllTo(HIGH);
  Serial.begin(9600);
}

void loop() {

    if(Serial.available()){
      brightness = Serial.readStringUntil('\n');
      shiftregister.setBrightness(brightness.toInt());
    } 
}
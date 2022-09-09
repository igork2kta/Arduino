/*Autor Igor Pinheiro da Silva 09/09/2022 */

#include <ShiftRegister.h>

//Alterar para os pinos de preferência
const byte dataPin = 2;
const byte latchPin = 3;
const byte clockPin = 4; 
const byte oePin = 5; //Precisa ser PWM

//Criação de um objeto do tipo sr(ShiftRegister)

sr shiftregister(dataPin,latchPin,clockPin, oePin);
void setup() {
  shiftregister.setBrightness(255);
}

void loop() {
    //Ativa todos os Pinos
    shiftregister.setAllTo(HIGH);
    delay(1000);
    
    for (int i = 255; i >= 0; i--)  //Apaga a saída gradualmente
    {
		shiftregister.setBrightness(i);
		delay(50);
    }

    delay(1000);
}
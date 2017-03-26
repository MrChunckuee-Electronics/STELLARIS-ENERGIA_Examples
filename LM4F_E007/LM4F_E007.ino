/*******************************************************************************
 *
 *                  Comunicacion con bluetooth
 *
 *******************************************************************************
 * FileName:        LM4F_E007.ino
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez Ramírez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Encender y apagar el LED 
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      11/03/2017      Creación del firmware
 ******************************************************************************/

unsigned char inputByte = 0; // incoming serial byte

void setup(){
  Serial2.begin(9600); // Velocidad de transmision de 9600bps
  pinMode(BLUE_LED, OUTPUT); //LED azul como salida
  digitalWrite(BLUE_LED,LOW); //Iniciamos con el LED apagado
}

void loop(){
  if (Serial2.available() > 0) {
    inputByte = Serial2.read(); // Leemos dato de entrada
    switch(inputByte){
      case 'a': // Encendemos LED
        digitalWrite(BLUE_LED,HIGH); 
      break;
      case 'b': // Apagamos LED
        digitalWrite(BLUE_LED,LOW); 
      break;
      default:
        digitalWrite(BLUE_LED,LOW); 
      break;
    }    
  }
}

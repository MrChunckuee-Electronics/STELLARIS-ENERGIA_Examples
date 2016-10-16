/*******************************************************************************
 *
 *                  Manejo del puerto serie
 *
 *******************************************************************************
 * FileName:        LM4F_E002
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Este ejemplo basico para el manejo del puerto serial
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      14/10/2016      Creación del firmware
 ******************************************************************************/

unsigned char inputByte = 0; // incoming serial byte

void setup(){
// start serial port at 9600 bps
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop(){
  if (Serial.available() > 0) {
    inputByte = Serial.read(); // get incoming byte
    switch(inputByte){
      case 'a':
        digitalWrite(RED_LED,HIGH); 
        Serial.print("LED Rojo encendido\n");
      break;
      case 'b':
        digitalWrite(RED_LED,LOW); 
        Serial.print("LED Rojo apagado");
      break;
      case 'c':
        digitalWrite(GREEN_LED,HIGH); 
        Serial.print("LED Verde encendido");
      break;
      case 'd':
        digitalWrite(GREEN_LED,LOW);
       Serial.print("LED Verde apagado"); 
      break;
      case 'e':
        digitalWrite(BLUE_LED,HIGH); 
        Serial.print("LED Azul encendido");
      break;
      case 'f':
        digitalWrite(BLUE_LED,LOW); 
        Serial.print("LED Azul apagado");
      break;
      case 'g':
        digitalWrite(RED_LED,LOW); 
        digitalWrite(GREEN_LED,LOW); 
        digitalWrite(BLUE_LED,LOW); 
        Serial.print("LEDs apagados");
      break;
      default:
        digitalWrite(RED_LED,LOW); 
        digitalWrite(GREEN_LED,LOW); 
        digitalWrite(BLUE_LED,LOW); 
      break;
    }    
  }
}



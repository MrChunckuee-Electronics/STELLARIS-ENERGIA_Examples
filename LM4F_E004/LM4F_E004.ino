/*******************************************************************************
 *
 *                  Entradas analogicas
 *
 *******************************************************************************
 * FileName:        LM4F_E004.ino
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez Ramírez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Ejemplo basico para para usar el ADC, leer temperatura del 
                    LM35 y mostrarlo en el monitor serial.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      27/10/2016      Creación del firmware
 ******************************************************************************/

const int pinLM35 = A0; // Pin analogico
int muestras, valueADC = 0; 
float mvADC = 0;
float tempLM35 = 0;

void setup(){
  Serial.begin(9600); // Start serial port at 9600 bps 
}

void loop(){
  // read the analog in value:
  valueADC+=analogRead(pinLM35); 
  muestras++;
  if(muestras==32){
    muestras=0;
    valueADC=valueADC>>5;
    tempLM35=valueADC*0.08;
    Serial.print("Temperatura: "); 
    Serial.print(tempLM35); 
    Serial.print(" C\n");
  }
  delay (32);
}

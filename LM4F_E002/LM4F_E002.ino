/*******************************************************************************
 *
 *                  Uso de salidas analogicas
 *
 *******************************************************************************
 * FileName:        LM4F_E002
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Este ejemplo enciende LEDs RBG de forma aleatorea.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      31/08/2016      Creación del firmware
 ******************************************************************************/

#define LED_RED     PB_0
#define LED_GREEN   PD_0
#define LED_BLUE    PB_5
 
void setup() {   
  //Pines como salidas
  pinMode(LED_RED, OUTPUT);     
  pinMode(LED_GREEN, OUTPUT); 
  pinMode(LED_BLUE, OUTPUT);  
}

void loop() {
 //Genera colores aleatoreamente
 SetColorLED(random(255), random(255), random(255)); 
 delay(500);
}

void SetColorLED(int RED, int GREEN, int BLUE){
  analogWrite(LED_RED, RED);
  analogWrite(LED_GREEN, GREEN);
  analogWrite(LED_BLUE, BLUE);
}



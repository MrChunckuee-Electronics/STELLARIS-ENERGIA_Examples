/*******************************************************************************
 *
 *                  Uso de entradas y salidas digitales
 *
 *******************************************************************************
 * FileName:        LM4F_E001
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Este ejemplo enciende los LEDs dependiendo de la cantidad
                    de veces que se precione el boton PUSH1.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      12/06/2016      Creación del firmware
 ******************************************************************************/

char count;

void setup() {                
  // Inicializa entradas y salidas
  // Activamos Pull-Up en PUSH1
  pinMode(RED_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT); 
  pinMode(BLUE_LED, OUTPUT); 
  pinMode(PUSH1, INPUT_PULLUP);
  count=0;
}

void loop() {
 ReadInputs();
 SetOutputs(); 
}

void ReadInputs (){
  if (digitalRead(PUSH1)==LOW){ //Checamos el estado de PUSH1
    count = count + 1;
    if(count>4) count = 1;
    while(digitalRead(PUSH1)==LOW);
    delay(1);
  }
}

void SetOutputs(){
  switch(count){//Colocamos las salidad dependiendo del estado de count
    case 1:
    digitalWrite(RED_LED, HIGH);   
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW); 
    break;
    case 2:
    digitalWrite(RED_LED, LOW);   
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    break;
    case 3:
    digitalWrite(RED_LED, LOW);   
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    break;
    case 4:
    digitalWrite(RED_LED, HIGH);   
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    break;   
    default:
    digitalWrite(RED_LED, LOW);   
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    break;
  }
}

/*******************************************************************************
 *
 *                  Graficar temperatura del LM35
 *
 *******************************************************************************
 * FileName:        LM4F_E005.ino
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez Ramírez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     En este ejemplo graficaremos en processing la señal de 
                    temperatura proveniente del sensor LM35.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      27/10/2016      Creación del firmware
 ******************************************************************************/

const int pinLM35 = A0; // Pin analogico
int tMax = 1900; //Limitamos pa no mandar mas de 150°C
int valueADC = 0; //Para almacenar el valor del ADC
char inByte, muestras;
char sendByte[4] = {0,0,0,0};

void setup(){
  Serial.begin(9600); // Start serial port at 9600 bps 
}

void loop(){
  // Los datos se encias aproximadamente cada 100 ms
  // Read the analog in value:
  valueADC+=analogRead(pinLM35); 
  muestras++;
  if(muestras==32){
    muestras=0;
    valueADC=valueADC>>5;
    if(valueADC>=tMax) valueADC = tMax;
    sendByte[0]=(char)(valueADC);
    sendByte[1]=(char)(valueADC>>8);
    Serial_SendData(sendByte, 4);
    }
    delay (3); 
}

/*******************************************************************************
 * Function:        void Serial_SendData(char data[], char len)
 * Description:     Envia el array con la temperatura
 * Precondition:    None
 * Parameters:      char data[] = Array a enviar, char len = Tamaño del array
 * Return Values:   None
 * Remarks:         None
 * *****************************************************************************/
void Serial_SendData(char data[], char len){
  char index=0;
  while(index<len){
    Serial.print(data[index]);
    index++;
  }  
}

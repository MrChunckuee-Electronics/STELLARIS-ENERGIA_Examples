/*******************************************************************************
 *
 *                  Uso de dos puertos serie
 *
 *******************************************************************************
 * FileName:        LM4F_E006.ino
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez Ramírez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Ejemplo basico para la comunicacion serial entre dos puertos,
                    la informacion enviada entre ellos se vera en los monitores 
                    seriales de energia y arduino.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      11/03/2017      Creación del firmware
 ******************************************************************************/
unsigned char inputByte1 = 0; 
unsigned char inputByte2 = 0;

void setup(){
  //Inicimos velocidad de transmision
  Serial.begin(9600);
  Serial2.begin(9600);
  //LEDs como salida 
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  //Apagamos LEDs
  digitalWrite(RED_LED, LOW);   
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  //Mensajes de inicio
  Serial.println("Hello world! by MrChunckuee");
  Serial2.println("Hello world! by MrChunckuee");
  Serial.println("Monitor Serial No.1");
  Serial2.println("Monitor Serial No.2");
}

void loop() {
  //Si se recive dato por el seial 1
  if (Serial.available() > 0) {
    inputByte1 = Serial.read();//Leemos valor recivido 
    Serial.print("Enviaste: ");
    Serial.write(inputByte1);
    Serial.println("");
    Serial2.print("Recibiste: ");//Mostramos en el monitor 2
    Serial2.write(inputByte1); 
    Serial2.println("");
    digitalWrite(RED_LED, LOW);   
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    delay(100);
  }
  //Si se recive dato por el serial 2
  //este puerto estara conectado al FT323
  if (Serial2.available() > 0) {
    inputByte2 = Serial2.read(); //Leemos valor recivido
    Serial2.print("Enviaste: ");
    Serial2.write(inputByte2);
    Serial2.println("");
    Serial.print("Recibiste: ");
    Serial.write(inputByte2); //Mostramos en el monitor 1
    Serial.println("");
    digitalWrite(RED_LED, LOW);   
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(100);
  }
  digitalWrite(RED_LED, HIGH);//Mientras no se envien datos enciende LED rojo   
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}



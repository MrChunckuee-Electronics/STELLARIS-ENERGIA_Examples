/*******************************************************************************
 *
 *    Envio de datos al puerto serie para monitoreo en Python
 *
 *******************************************************************************
 * FileName:        LM4F_E000.ino
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 0101e0017
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Este ejemplo envia un valor tipo Int atraves del puerto serie, 
 *                  para ser procesado en Python, ademas de cambiar el estado del 
 *                  LED azul
 *******************************************************************************
 * Rev.         Date            Comment
 *   v0.0.0     22/02/2019      Creación del firmware
 *   v0.0.1     02/03/2019      Se implemento retardos usando millis()
 ******************************************************************************/

const int pinButton = PUSH1;
const int pinLed =  BLUE_LED;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)
int buttonState = 0;
int buttonTicks = 0;
int currentButtonState = 0;
int lastButtonState= 0;
int buttonFlag = LOW;
unsigned int send_data = 0;

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT); 
  Serial.begin(9600);     
}

void loop(){
  GetInput();
  if(buttonFlag == HIGH){
    // check to see if it's time to blink the LED; that is, if the 
    // difference between the current time and last time you blinked 
    // the LED is bigger than the interval at which you want to 
    // blink the LED.
    unsigned long currentMillis = millis();
 
    if(currentMillis - previousMillis > interval) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      
      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW){
        ledState = HIGH;
        Serial.print(send_data); //When use .read() in python
        //Serial.println(send_data); //When use .readline() in python
        send_data ++;
        if(send_data == 400) //Limitamos a mandar 400 valores
            send_data= 0;
      }
      else
        ledState = LOW;

      // set the LED with the ledState of the variable:
      digitalWrite(pinLed, ledState);
      }
    }
}

void GetInput(void){
  // Push Button debounce
  if (buttonState != digitalRead(pinButton)){
    if (buttonTicks > 20){
      buttonState = digitalRead(pinButton);
      buttonTicks = 0;
      }
      else buttonTicks++;
  }
  else buttonTicks = 0;
  // Process the push button
  currentButtonState = buttonState;
  if (currentButtonState == 0 && lastButtonState == 1){
    
    if (buttonFlag == LOW){
      send_data= 0;
      buttonFlag = HIGH;
      }
    else{
      buttonFlag = LOW;
      digitalWrite(pinLed, LOW);
      send_data= 0;
      }
  }
  lastButtonState = currentButtonState;   
}


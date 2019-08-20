/*******************************************************************************
 *
 *    Prueba del sensor DHT22 - Envio de datos al monitor serial de Energia
 *
 *******************************************************************************
 * FileName:        LM4F_E010.ino
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 1.6.10E18
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Este ejemplo se basa en la libreria de Adafruit para el 
 *                  sensor de temperatura y humedad DHT22, cuando sepulsa SW1
 *                  la Stellaris envia los datos al monitor serial y realiza 
 *                  un blink en el LED Azul, cuando se vuelve a pulsar SW1 el 
 *                  envio se detiene y tambien el blink. 
 *******************************************************************************
 * Rev.         Date            Comment
 *   v0.0.0     04/06/2019      Creación del firmware
 ******************************************************************************/

#include "DHT.h"

#define DHTPIN PB_5     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

const int pinButton = PUSH1;
const int pinLed =  BLUE_LED;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long interval = 1500;           // interval at which to blink (milliseconds)
int buttonState = 0;
int buttonTicks = 0;
int currentButtonState = 0;
int lastButtonState= 0;
int buttonFlag = LOW;

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT); 
  Serial.begin(9600);
  dht.begin();
  delay(3000);
  Serial.println("DHT22 test! by MrChunckue - Electronica&Robotica");  
  Serial.println("Pulsa SW1 para enviar datos de Humedad y Temperatura");
  Serial.println(" "); 
}

void loop(){
  GetInput();
  if(buttonFlag == HIGH){
    unsigned long currentMillis = millis();
 
    if(currentMillis - previousMillis > interval) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      
      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW){
        ledState = HIGH;

        //Se lee temperatura y humedad
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        Serial.print("Humedad: ");
        Serial.print(h);
        Serial.print(" %\t");
        Serial.print("Temperatura: ");
        Serial.print(t);
        Serial.println(" *C ");
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
      buttonFlag = HIGH;
      Serial.println("Enviando datos cada 3 segundos!!");
      }
    else{
      buttonFlag = LOW;
      digitalWrite(pinLed, LOW);
      Serial.println("Se detuvo el envio de datos!!");
      Serial.println(" ");
      }
  }
  lastButtonState = currentButtonState;   
}

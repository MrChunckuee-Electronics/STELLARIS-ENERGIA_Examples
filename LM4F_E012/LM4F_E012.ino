/*******************************************************************************
 *
 *    Control de motor paso a paso con el driver BD63873EFV
 *
 *******************************************************************************
 * FileName:        LM4F_E012.ino
 * Processor:       EX-LM4F120XL
 * Complier:        Energia 1.6.10E18
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Este ejemplo es un testo para control de un motor paso a paso 
 *                  con el driver BD63873EFV, ambos rescatados de una vieja impresora
 *******************************************************************************
 * Rev.         Date            Comment
 *   v0.0.0     25/03/2019      Creación del firmware
 ******************************************************************************/

#define pinButton1        PUSH1
#define pinLedRedStatus   RED_LED
#define pinLedGreenStatus GREEN_LED
#define pinLedBlueStatus  BLUE_LED
#define pinClkDriver      PA_2
#define pinCwCcwDriver    PA_3
#define pinMode0Driver    PA_4
#define pinMode1Driver    PB_6
#define pinEnableDriver   PB_7
#define pinPSDriver       PF_0

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long interval = 10;           // interval at which to blink (milliseconds)

void setup() {
  pinMode(pinButton1, INPUT_PULLUP);
  pinMode(pinLedRedStatus, OUTPUT);
  pinMode(pinLedGreenStatus, OUTPUT);
  pinMode(pinLedBlueStatus, OUTPUT);
  pinMode(pinClkDriver, OUTPUT);
  pinMode(pinCwCcwDriver, OUTPUT);
  pinMode(pinMode0Driver, OUTPUT);
  pinMode(pinMode1Driver, OUTPUT);
  pinMode(pinEnableDriver, OUTPUT);
  pinMode(pinPSDriver, OUTPUT);

  //Init default driver
  digitalWrite(pinCwCcwDriver, LOW); //Clockwise
  digitalWrite(pinMode0Driver, LOW); //Full step
  digitalWrite(pinMode1Driver, LOW); //Full step
  digitalWrite(pinEnableDriver, HIGH); //Active
  digitalWrite(pinPSDriver, HIGH); //Active
}

void loop() {
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > interval) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW)
        ledState = HIGH;
      else
        ledState = LOW;
      // set the LED with the ledState of the variable:
      digitalWrite(pinLedGreenStatus, ledState);
      digitalWrite(pinClkDriver, ledState);
      }    
}

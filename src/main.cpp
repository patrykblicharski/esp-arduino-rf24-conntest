/*
Defined environments:
  ARDUINO_BUILD
  ESP13_BUILD 
  NODEMCU_BUILD

Global variables:
  VERSION
  DEBUG
Variables of environments:
  RF_CE_PIN 
  RF_CSN_PIN
  SERIALSPEED
  UPLOAD_SPEED
Defined global functions
  DEBUG_PRINT(x) 
  DEBUG_PRINTDEC(x) 
  DEBUG_PRINTLN(x) 
  DEBUG_PRINTF(x,y)
*/

#include <Arduino.h>
#include <SPI.h>
#include "printf.h"
#include "RF24.h"

#include "env_def.h"


RF24 radio(RF_CE_PIN,RF_CSN_PIN);     // Init radio bus pins

const uint8_t num_channels = 126;     // Channel info
uint8_t values[num_channels];         //




void setup() {
  Serial.begin(SERIALSPEED);
  

}

void loop() {
  
}


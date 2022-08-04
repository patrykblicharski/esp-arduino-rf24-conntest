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

uint8_t address[][6] = {"1Node", "2Node"};

bool radioNumber = 1; // 0 uses address[0] to transmit, 1 uses address[1] to transmit
bool role = false;  // true = TX node, false = RX node

struct PayloadStruct {      // Make a data structure to store the entire payload of different datatypes
  char message[7];          // only using 6 characters for TX & RX payloads
  uint8_t counter;          // an integer number that will be incremented on every successful transmission.
};
PayloadStruct payload;      

void setup() {
  Serial.begin(SERIALSPEED);

  #ifdef DEBUG
  //  printf_begin();             // needed only once for printing details
  //  radio.printDetails();       // (smaller) function that prints raw register values
  radio.printPrettyDetails(); // (larger) function that prints human readable data
  #endif


  payload.message[6] = 123;

  if (!radio.begin()) {
    DEBUG_PRINTLN(F("radio hardware is not responding!!"));
    while (1) {}                                  
  }

  DEBUG_PRINTLN(F("Which radio is this? Enter '0' or '1'. Defaults to '0'"));
  
  while (!Serial.available()) { /* Wait for user input */  }
  char input = Serial.parseInt();
  radioNumber = input == 1;
  DEBUG_PRINT(F("radioNumber = "));
  DEBUG_PRINTLN((int)radioNumber);

  radio.setPALevel(RF24_PA_LOW);                  // RF24_PA_MAX is default.
  radio.setPayloadSize(sizeof(payload));          // char[7] & uint8_t datatypes occupy 8 bytes

  radio.openWritingPipe(address[radioNumber]);     // set the TX address of the RX node into the TX pipe // always uses pipe 0
  radio.openReadingPipe(1, address[!radioNumber]); // set the RX address of the TX node into a RX pipe // using pipe 1
   
   if (role) {
    // setup the TX node
    memcpy(payload.message, "Hello ", 6); 
    radio.stopListening();                          // put radio in TX mode
  } else {
    // setup the RX node
    memcpy(payload.message, "World ", 6); 
    radio.startListening();                         // put radio in RX mode
  }

}//end setup()

void loop() {  


//TODO

/*
 if (Serial.available()) {
    char c = toupper(Serial.read());
    if (c == 'T' && !role) {
      // Become the TX node

      role = true;
      memcpy(payload.message, "Hello ", 6); // set the outgoing message
      DEBUG_PRINTLN(F("*** CHANGING TO TRANSMIT ROLE -- PRESS 'R' TO SWITCH BACK"));
      radio.stopListening();                // put in TX mode

    } else if (c == 'R' && role) {
      // Become the RX node

      role = false;
      memcpy(payload.message, "World ", 6); // set the response message
      DEBUG_PRINTLN(F("*** CHANGING TO RECEIVE ROLE -- PRESS 'T' TO SWITCH BACK"));
      radio.startListening();               // put in RX mode
    }
  }
*/
}


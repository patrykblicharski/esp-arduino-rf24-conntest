const int _serialspeed = SERIALSPEED;


#ifdef NODEMCU_BUILD
  #define RF_CE_PIN 2 //Nodemcu pin D2 (GPIO4)
  #define RF_CSN_PIN 4 //Nodemcu pin D4 (GPIO2)
#endif
#ifdef ESP13_BUILD
  #define RF_CE_PIN 4 //GPIO 4
  #define RF_CSN_PIN 2 //GPIO 2
#endif

#ifdef ARDUINO_BUILD
  #define RF_CE_PIN 9   //Arduino pin D9
  #define RF_CSN_PIN 10   //Arduino pin D10
#endif
#ifdef  SERIALSPEED

#endif 

#ifdef DEBUG
  #define DEBUG_PRINT(x)     Serial.print (x)
  #define DEBUG_PRINTDEC(x)     Serial.print (x, DEC)
  #define DEBUG_PRINTLN(x)  Serial.println(x)
 // #define DEBUG_PRINTF(x, y) printf(x, y)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTDEC(x)
  #define DEBUG_PRINTLN(x) 
  //#define DEBUG_PRINTF(x, y)
#endif

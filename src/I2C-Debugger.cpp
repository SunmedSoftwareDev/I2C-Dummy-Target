#include "application.h"
#include "I2C-Debugger.h"
/*
 * Project I2C-Debugger
 * Description:  Main code for I2C slave for r-90 debug code
 * Author:  JJ Fenstermaker
 * Date: 7/23/19
 */

PRODUCT_ID(I2C_DEBUGGER); //This is the number found in the console
PRODUCT_VERSION(0); // Increase this number each time  FW is uploaded to the console


String fwrev = VERSION; // This is the value checked to determine if an update is required

//system_thread enables the dual processing
SYSTEM_THREAD(ENABLED);
//must call Particle.connect() to connect to cloud in manual or semi-auto
SYSTEM_MODE(
  AUTOMATIC);

//Allows for the reset reason to be used
STARTUP(System.enableFeature(FEATURE_RESET_INFO));

// reset the system after 60 seconds if the application is unresponsive
ApplicationWatchdog wd(6000, System.reset,1024);
int8_t heartBeatCounter = 0;



// setup() runs once, when the device is first turned on.

void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(921600);
  delay(500);

  Wire.setSpeed(CLOCK_SPEED_100KHZ);
  Wire.stretchClock(true);
  Wire.begin(DEBUGGER_SLAVE_ADDRESS);

  Wire.onReceive(receiveEvent); // register event  
  Wire.onRequest(requestEvent); // register event

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  delay(500);
  if(heartBeatCounter >= 20){
    Serial.println("Debugger Heartbeat");
    heartBeatCounter = 0;
  } 
  else
  {
    heartBeatCounter+=1;
  }
  
  wd.checkin();
}
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while(1 < Wire.available()) { // loop through all but the last
    char c = Wire.read();       // receive byte as a character
    Serial.print(c);            // print the character
  }
  int16_t x = Wire.read();          // receive byte as an integer
  Serial.printlnf("%d",x);            // print the integer
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {

  Wire.write("hello ");         // respond with message of 6 bytes as expected by master
}


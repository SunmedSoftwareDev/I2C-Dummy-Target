#include "application.h"
#include "I2C-Receiver.h"
/*
 * Project I2C-Receiver
 * Description:  Main code for I2C slave for r-90 debug code
 * Author:  JJ Fenstermaker
 * Date: 7/23/19
 */

PRODUCT_ID(I2C_RECEIVER); //This is the number found in the console
PRODUCT_VERSION(0); // Increase this number each time  FW is uploaded to the console


String fwrev = VERSION; // This is the value checked to determine if an update is required

//system_thread enables the dual processing
SYSTEM_THREAD(ENABLED);
//must call Particle.connect() to connect to cloud in manual or semi-auto
SYSTEM_MODE(SEMI_AUTOMATIC);

//Allows for the reset reason to be used
STARTUP(System.enableFeature(FEATURE_RESET_INFO));

// reset the system after 60 seconds if the application is unresponsive
ApplicationWatchdog wd(60000, System.reset,1024);




// setup() runs once, when the device is first turned on.
void setup();
void loop();

void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(921600);
  Wire.begin(SLAVE_ADDRESS);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  delay(1);
  

}
/*************************************************** 
  This is an example for the HiTach SD Card Logger with RTC board


 ****************************************************/

// include SPI and SD libraries
#include <SPI.h>
#include <SD.h>
#include <Wire.h> //for rtc on I2C
#include "RTClib.h"
const int CS_PIN = 10;

void setup() {
  
  
  Serial.begin(9600);
  Serial.println("Initializing SD Card");
  
  //CS pin must be configured as Outpot
  pinMode(CS_PIN,OUTPUT);

   if (!SD.begin(CS_PIN)) 
   {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more 
   }
Serial.println("CD Initialized");
}

void loop() {
  String dataString = "Hello There";

  long  timeStamp = millis();

  //Open a file and write to it
  File dataFile = SD.open("log.csv",FILE_WRITE);
  if (dataFile)
  {
   dataFile.print(timeStamp);
   dataFile.print(",");
   dataFile.println(dataString);
   dataFile.close(); //Run close() to force data to be writen

   //Print same thing to the screen
   Serial.print(timeStamp);
   Serial.print(" ,");
    Serial.println(dataString);
  }
  else
  {
    Serial.print("Couldn't open log file");
    while (1); //don't do anything more
  }
  //while (1);  // don't do anything more 
  /*String commandFile; 
  String log_msg;
  File commandFile = SD.open("log.csv");
  if(commandFile)
  {
   Serial.print("Reading log file");
   while(commandFile.available())
    {
     log_msg = commandFile.parseInt();
    }
    Serial.print("Log Message = ");
    Serial.print(log_msg);
  }
  else
  {
   Serial.println("Could not read log file.");
  }
  */
  delay(5000);

//while(1);
}  
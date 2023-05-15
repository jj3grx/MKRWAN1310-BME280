/*
  Lora Send And Receive
  This sketch demonstrates how to send and receive data with the MKR WAN 1300/1310 LoRa module.
  This example code is in the public domain.
*/

#include <MKRWAN.h>

LoRaModem modem;

// Uncomment if using the Murata chip as a module
// LoRaModem modem(Serial1);

#include "arduino_secrets.h"
// Please enter your sensitive data in the Secret tab or arduino_secrets.h
String appEui = SECRET_APP_EUI;
String appKey = SECRET_APP_KEY;

//#include <SPI.h>
#include <Wire.h>

#include "SparkFunBME280.h"
BME280 mySensor;

float temp;
float humid;
float pressure;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Reading basic values from BME280");

  Wire.begin();
  mySensor.setI2CAddress(0x76);

  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }


}

void loop() {
  Serial.print(" Temp: ");
  temp = mySensor.readTempC();
  Serial.println(temp,2);

  Serial.print(" Pressure (hPa): ");
  pressure = mySensor.readFloatPressure()/100.0;
  Serial.println(pressure,2);


  delay(1000);  

}

/* HM6352 Compass sensor library
By Daniel Britten
V1.0

Main Program must include
Wire.begin();
*/

#include "Arduino.h"
#include "Compass.h"
#include <Wire.h>

Compass::Compass() {
  
}

float Compass::heading(){
  int HMC6352SlaveAddress = 0x42;
  int HMC6352ReadAddress = 0x41;
  HMC6352SlaveAddress = HMC6352SlaveAddress >> 1;
  //"Get Data. Compensate and Calculate New Heading"
  Wire.beginTransmission(HMC6352SlaveAddress);
  Wire.write(HMC6352ReadAddress);              // The "Get Data" command
  Wire.endTransmission();

  //time delays required by HMC6352 upon receipt of the command
  //Get Data. Compensate and Calculate New Heading : 6ms
  delay(6);

  Wire.requestFrom(HMC6352SlaveAddress, 2); //get the two data bytes, MSB and LSB

  //"The heading output data will be the value in tenths of degrees
  //from zero to 3599 and provided in binary format over the two bytes."
  byte MSB = Wire.read();
  byte LSB = Wire.read();

  float headingSum = (MSB << 8) + LSB; //(MSB / LSB sum)
  float headingInt = headingSum / 10; 

  return headingInt;
}

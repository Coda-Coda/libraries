#include "MotorDriver.h"

MotorDriver::MotorDriver(int address)
{
    _leftSpeed = 500;
    _rightSpeed = 500;
    _address = address;
}

void MotorDriver::setup()
{
    
}

void MotorDriver::straight(float cm)
{
    char *f_cm = dtostrf(cm, 3, 1, _buffer);
    writeToWire(1, f_cm);
}

void MotorDriver::rotate(float deg)
{
    char *f_deg = dtostrf(deg, 3, 1, _buffer);
    writeToWire(2, f_deg);
}

void MotorDriver::swingWithRight(float deg)
{
    char *f_deg = dtostrf(deg, 3, 1, _buffer);
    writeToWire(3, f_deg);
}

void MotorDriver::swingWithLeft(float deg)
{
    char *f_deg = dtostrf(deg, 3, 1, _buffer);
    writeToWire(4, f_deg);
}

void MotorDriver::setActiveSpeeds(float left, float right)
{
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    writeToWire(5, b);
}

void MotorDriver::setSpeeds(float left, float right)
{
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    writeToWire(6, b);
}

void MotorDriver::setMaxSpeeds(float left, float right)
{
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    writeToWire(7, b);
}

void MotorDriver::setAccelerations(float left, float right)
{
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    writeToWire(8, b);
}

boolean MotorDriver::running()
{
    writeToWire(9, "");
    Wire.requestFrom(_address, 1);
    if (Wire.available())
    {
	if (Wire.read() == 1)
	{
	    Serial.println("Says it's running.");
	    return true;
	}
	else
	{
	    Serial.println("Says it's not running.");
	    return false;
	}
	//return (Wire.read() == 1);
    }
    return true;
}

void MotorDriver::wait()
{
    while (running()) {Serial.println("Waiting...");} //Let the other arduino do its thing
}

long MotorDriver::cmToSteps(float cm)
{
    return (long)((cm * 1600.0)/(6.46 * 3.14159265358979));
}

void MotorDriver::writeToWire(int code, char *str)
{
    Serial.println("Beginning transmission to address.");
    Wire.beginTransmission(_address);
    Serial.println("Writing code to address.");
    Wire.write(code);
    Serial.print("Wrote code ");
    Serial.print(code);
    Serial.print(" to ");
    Serial.println(_address, HEX);
    if (str != "")
    {
	Wire.write(str);
	Serial.print("Wrote data '");
	Serial.print(str);
	Serial.println("'.");
    }
    Wire.endTransmission();
}

void MotorDriver::writeToWire(int code, long val1, long val2)
{
    Wire.beginTransmission(_address);
    Wire.write(code);
    Wire.write((val1 & 0xF000) >> 24);
    Wire.write((val1 & 0x0F00) >> 16);
    Wire.write((val1 & 0x00F0) >> 8);
    Wire.write(val1 & 0x000F);

    Wire.write((val2 & 0xF000) >> 24);
    Wire.write((val2 & 0x0F00) >> 16);
    Wire.write((val2 & 0x00F0) >> 8);
    Wire.write(val2 & 0x000F);
    Wire.endTransmission();
}


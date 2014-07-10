#include "MotorDriver.h"

MotorDriver::MotorDriver(int address)
{
    _leftSpeed = 500;
    _rightSpeed = 500;
}

MotorDriver::setup()
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
    char *f_left = dtostrf(left, 3, 1, _buffer);
    char *f_right = dtostrf(right, 3, 1, _buffer);
    writeToWire(5, f_left + "," + f_right);
}

void MotorDriver::setSpeeds(float left, float right)
{
    char *f_left = dtostrf(left, 4, 1, _buffer);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    writeToWire(6, f_left + "," + f_right);
}

void MotorDriver::setMaxSpeeds(float left, float right)
{
    char *f_left = dtostrf(left, 3, 1, _buffer);
    char *f_right = dtostrf(right, 3, 1, _buffer);
    writeToWire(7, f_left + "," + f_right);
}

void MotorDriver::setAccelerations(float left, float right)
{
    char *f_left = dtostrf(left, 3, 1, _buffer);
    char *f_right = dtostrf(right, 3, 1, _buffer);
    writeToWire(8, f_left + "," + f_right);
}

boolean MotorDriver::running()
{
    writeToWire(9, "");
    while (Wire.available())
    {
	running = (boolean)Wire.read();
    }
}

void MotorDriver::wait()
{
    while (running()) {} //Let the other arduino do its thing
}

long MotorDriver::cmToSteps(float cm)
{
    return (long)((cm * 1600.0)/(6.46 * 3.14159265358979));
}

void MotorDriver::writeToWire(byte code, char *str)
{
    Wire.beginTransmission(_address);
    Wire.write(code);
    if (str != "") Wire.write(str);
    Wire.endTransmission();
}

void MotorDriver::writeToWire(byte code, long val1, long val2)
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


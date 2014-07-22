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
    //char *f_cm = dtostrf(cm, 3, 1, _buffer);
    writeToWire(1, cm, 0.0);
}

void MotorDriver::rotate(float deg)
{
    //char *f_deg = dtostrf(deg, 3, 1, _buffer);
    writeToWire(2, deg, 0.0);
}

void MotorDriver::swingWithRight(float deg)
{
    //char *f_deg = dtostrf(deg, 3, 1, _buffer);
    writeToWire(3, deg, 0.0);
}

void MotorDriver::swingWithLeft(float deg)
{
    //char *f_deg = dtostrf(deg, 3, 1, _buffer);
    writeToWire(4, deg, 0.0);
}

void MotorDriver::setActiveSpeeds(float left, float right)
{
    /*
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    */
    writeToWire(5, left, right);
}

void MotorDriver::setSpeeds(float left, float right)
{
    /*
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    */
    writeToWire(6, left, right);
}

void MotorDriver::setMaxSpeeds(float left, float right)
{
    /*
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    */
    writeToWire(7, left, right);
}

void MotorDriver::setAccelerations(float left, float right)
{
    /*
    char b[25];
    char *f_left = dtostrf(left, 4, 1, _buffer);
    strcpy(b, f_left);
    char *f_right = dtostrf(right, 4, 1, _buffer);
    strcat(b, ",");
    strcat(b, f_right);
    */
    writeToWire(8, left, right);
}

boolean MotorDriver::running()
{
    Wire.requestFrom(_address, 1);
    if (Wire.available())
    {
	if (Wire.read() != 0)
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
    while (running()) {Serial.println("Waiting..."); delay(30);} //Let the other arduino do its thing
}

void MotorDriver::writeToWire(int code, float val1, float val2)
{
    Serial.println("Beginning transmission to address.");
    Wire.beginTransmission(_address);
    Wire.write(code);

    union u_tag
    {
        byte b[4];
        float fval;
    } u;

    u.fval = val1;
    Wire.write(u.b, 4);
    
    u.fval = val2;
    Wire.write(u.b, 4);
    int e = Wire.endTransmission();
    Serial.print("Received code ");
    Serial.println(e);
}


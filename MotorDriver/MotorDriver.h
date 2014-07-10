/* A  class for transmitting movement data over I2C to the Arduino controlling
 * motors, as opposed to directly using Motors library. 
 * 
 * Author: Aaron Keesing, 2014
 * License: Public Domain
 * Version: 1.0
 */

#include "Arduino.h"
#include "Wire.h"

class MotorDriver
{
public:
    MotorDriver(int address);
    void straight(float cm); //1
    void rotate(float deg); //2
    void swingWithRight(float deg); //3
    void swingWithLeft(float deg); //4
    void setActiveSpeeds(float left, float right); //5
    void setSpeeds(float left, float right); //6
    void setMaxSpeeds(float left, float right); //7
    void setAccelerations(float rightt, float right); //8

    void setup();
    //void run();
    //void runSpeed();
    boolean running(); //9
    void wait();

private:
    long cmToSteps(float cm);
    void writeToWire(byte code, char *str);
    void writeToWire(byte code, long val1, long val2);
    float _leftSpeed;
    float _rightSpeed;
    int _address;
    char _buffer[25];
}

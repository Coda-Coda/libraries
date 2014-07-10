/* HM6352 Compass sensor library
By Daniel Britten, 2013
V1.0
*/

#ifndef Compass_h
#define Compass_h

#include "Arduino.h"
#include <Wire.h>

class Compass
{
public:
    Compass();
    float heading();
    float correctedHeading();
};

#endif

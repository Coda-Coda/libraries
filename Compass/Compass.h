/* HM6352 Compass sensor library
By Daniel Britten
V1.0
*/

#ifndef Compass_h
#define Compass_h

#include "Arduino.h"

class Compass
{
  public:
    Compass();
    float heading();
  private:
    int _test;
};

#endif
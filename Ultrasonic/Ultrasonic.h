/*	Ultrasonic.h - Ultrasonic library, just to make the code a little cleaner
 *
 *	Author: Aaron Keesing
 *	Version: 1.0
 *	License: Released into the Public Domain
 *
 *	Yeah I know I just copied Daniel's summary but at least mine is
 *	formatted nicely.
 */
 
#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic
{
public:
	Ultrasonic(int trigger, int echo);
	float distance();
private:
	int triggerPin, echoPin;
};

#endif


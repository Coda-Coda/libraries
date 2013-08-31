/*	Ultrasonic.cpp - Definitions for Ultrasonic class
 *
 *	Author: Aaron Keesing
 *	Version: 1.0
 *	License: Released into the Public Domain
 */

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trigger, int echo)
{
	triggerPin = trigger;
	echoPin = echo;
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

float Ultrasonic::distance()
{
	long duration;
  
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);

	/* The 10us wait here is important */
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);

	/* duration is the time until echoPin goes HIGH (unless it times out) */
	duration = pulseIn(echoPin, HIGH, 3000); // 3000us would mean its beyond 50cm, which is good enough in our case
	if (duration == 0)
	{
		duration = 3000;
	}
	delay(50);
	return (float)duration / 58.4;
}


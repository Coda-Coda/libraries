/* LEDBarGraph.cpp - Class definitions for LEDBarGraph class
 *
 * Author: Aaron Keesing
 * Version: 1.0
 * License: Public Domain
 */

#include "LEDBarGraph.h"

LEDBarGraph::LEDBarGraph(int *pins, int numLeds)
{
	for (int i = 0; i < numLeds; i++)
	{
		_pins[i] = pins[i];
		pinMode(pins[i], OUTPUT);
		digitalWrite(pins[i], LOW);
	}
}

/* turnOnLED() turns on an LED, and if exclusive is true, turns off all the
   other LEDs. led is given as array index (i.e. starts at 0, not 1). */
void LEDBarGraph::turnOnLED(int led, bool exclusive)
{
	digitalWrite(_pins[led], HIGH);
	if (exclusive)
	{
		for (int i = 0; i < _numLeds && i != led; i++)
		{
			digitalWrite(_pins[i], LOW);
		}
	}
}

void LEDBarGraph::turnOffLED(int led)
{
	digitalWrite(_pins[led], LOW);
}

/* Writes a number in binary using LED on as 1, LED off as 0. 0 is first pin. */
void LEDBarGraph::writeBinary(unsigned int i)
{
	if (i > (1 << 8) - 1) return;
	for (int j = 0; j < 8; j++) 
	{
		digitalWrite(_pins[j], LOW);
		if ((1 << j) & i) digitalWrite(_pins[j], HIGH);
	}
}


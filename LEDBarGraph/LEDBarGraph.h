/* LEDBarGraph.h - Class for interfacing with LED arrays
 *
 * Author: Aaron Keesing
 * Version: 1.0
 * License: Public domain
 */

#include <Arduino.h>

class LEDBarGraph
{
public:
	LEDBarGraph(int *pins, int numLeds);
	void turnOnLED(int led, bool exclusive);
	void turnOffLED(int led);
	void writeBinary(unsigned int i);
	
private:
	int _numLeds;
	int *_pins;
};


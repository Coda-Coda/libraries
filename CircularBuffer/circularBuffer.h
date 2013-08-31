#ifndef Compass_h
#define Compass_h

#include "Arduino.h"

#define BUFFERSIZE = 100

class CircularBuffer
{
  public:
	CircularBuffer();
	void putValue(int);
	float getAverage();
  private:
  	int size;
	float buffer [BUFFER_SIZE];
	int position;
	int actualSize;
	int latestPutPosition ();
	int oldestPutPosition ();
}

#endif

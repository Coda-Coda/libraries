#ifndef CircularBuffer_h
#define CircularBuffer_h

#include "Arduino.h"

#define BUFFER_SIZE 10

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
};

#endif

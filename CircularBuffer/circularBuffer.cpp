#include "CircularBuffer.h"
#include "Arduino.h"

CircularBuffer::CircularBuffer()
{
  size=BUFFER_SIZE;
  position=0;
}

void CircularBuffer::putValue(float value)
{
  buffer[position]=value;
  position++;
  if (position==(size))
  {
    position=0;
  }
  if (actualSize!=size)
  {
     actualSize++;
  }
}



int CircularBuffer::latestPutPosition ()
{
  if (position == 0)
  {
    return (actualSize-1);
  }
  else
  {
    return (position-1);
  }
}

int CircularBuffer::oldestPutPosition ()
{
  if (actualSize<size)
  {
    return 0;
  }
  if (actualSize == size)
  {
    return position;
  }
  else return 0; //This line should never execute
}

float CircularBuffer::getAverage () {
  float sum = 0;
  for(int i=0; i<actualSize; i++){
    sum += buffer[i];
	yield();
  }
  return sum/actualSize;
}
typedef struct
{
  int size;
  int buffer [MAP_BUFFER_SIZE];
  int position;
  int actualSize;
}CircularBuffer;

void initBuffer(CircularBuffer &buffer)
{
  buffer.size=MAP_BUFFER_SIZE;
  buffer.position=0;
}

void putValue(CircularBuffer &buffer, int value)
{
  buffer.buffer[buffer.position]=value;
  buffer.position++;
  if (buffer.position==(buffer.size))
  {
    buffer.position=0;
  }
  if (buffer.actualSize!=buffer.size)
  {
     buffer.actualSize++;
  }
}



int latestPutPosition (CircularBuffer &buffer)
{
  if (buffer.position == 0)
  {
    return (buffer.actualSize-1);
  }
  else
  {
    return (buffer.position-1);
  }
}

int oldestPutPosition (CircularBuffer &buffer)
{
  if (buffer.position>MAP_BUFFER_SIZE)
  {
    return 0;
  }
  if (buffer.actualSize == MAP_BUFFER_SIZE)
  {
    return buffer.position;
  }
  else return 1; //Warning if the initial value was Green the total value will be INCORRECT!!!
}

/*

    for (int i=0; i<bufferSize; i++)
    {
      totalLeftGreen+=greenLeftBuffer[i];
    }


    for (int i=0; i<bufferSize; i++)
    {
      totalRightGreen+=greenRightBuffer[i];
    }



    if (totalLeftGreen>totalLeftGreenLowerThreshold)
    {
      greenState = 1;
    }
    if (totalRightGreen>totalRightGreenLowerThreshold)
    {
      greenState = 2;
    }
    */

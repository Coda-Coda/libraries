/* TCS2300 Library, based off example code from http://www.geeetech.com/wiki/index.php/Arduino_TCS230_Color_Recognition_Sensor_module

By Daniel Britten */


int flag=0;
int counter=0;
int countR=0,countG=0,countB=0;

void Colour::Colour(int s0, int s1, int s2, int s3)
{
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT); 
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
}
void Colour::TCS()
{
  digitalWrite(s1,HIGH);
  digitalWrite(s0,LOW);
  flag=0;
  attachInterrupt(0, ISR_INTO, CHANGE);
  timer2_init();
}
void Colour::ISR_INTO()
{
  counter++;
}
void Colour::timer2_init(void)
{
  TCCR2A=0x00;
  TCCR2B=0x07; //the clock frequency source 1024 points
  TCNT2= 100;    //10 ms overflow again
  TIMSK2 = 0x01; //allow interrupt
}

int i=0;

ISR(TIMER2_OVF_vect)//the timer 2, 10ms interrupt overflow again. Internal overflow interrupt executive function
{
TCNT2=100;
flag++;
if(flag==1)
 {
   counter=0;
 }
else if(flag==2)
  {
   digitalWrite(s2,LOW);
   digitalWrite(s3,LOW); 
   countR=counter/1.051;
   Serial.print("red=");
   Serial.println(countR,DEC);
   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);   
  }
else if(flag==3)
   {
    countG=counter/1.0157;
   Serial.print("green=");
   Serial.println(countG,DEC);
    digitalWrite(s2,LOW);
    digitalWrite(s3,HIGH); 
    }
else if(flag==4)
   {
    countB=counter/1.114;
   Serial.print("blue=");
   Serial.println(countB,DEC);
    digitalWrite(s2,LOW);
    digitalWrite(s3,LOW);
    }
else
    {
    flag=0; 
     TIMSK2 = 0x00;
    }
    counter=0;
    delay(2);
}
boolean Colour::isGreen()
{
 delay(10);
 TCS();
 if((countR>10)||(countG>10)||(countB>10))
  {
     if((countR>countG)&&(countR>countB))
      {
           Serial.print("red");
           Serial.print("\n");
           delay(1000);
		   return false;
      }
     else if((countG>=countR)&&(countG>countB))
      {
	       return true;
           Serial.print("green");
           Serial.print("\n");
           delay(1000);
      } 
    else if((countB>countG)&&(countB>countR))
     {
           Serial.print("blue");
           Serial.print("\n");
          delay(1000);
		  return false;
     }
   }
 else 
 {
    delay(1000);       
 }
}//Not functional
void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20; //아웃풋 모드
  TCCR1A = 0x03;
  TCCR1B = 0x0a;
  TCNT1 = 960;
  TIMSK1 = 0x01;

}


unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count;
int duty;

void loop() {
  // put your main code here, to run repeatedly:
      unsigned long currentMillis = millis();
      if(currentMillis - previousMillis > 20)
      {
        previousMillis = currentMillis;
        duty++;
        if(duty == 72)
        {
          duty = 22;
        }
      }
  

}

SIGNAL(TIMER1_OVF_vect)
{
  TCNT1 = 960;
  count++;
  if(count == 625)
  {
    count = 0;
    PORTB = 0x20;
  }
  else if(count == duty) //var 22~72
  {
    PORTB = 0x00;
  }
}


SIGNAL(TIMER1_COMPA_vect)
{
  
}

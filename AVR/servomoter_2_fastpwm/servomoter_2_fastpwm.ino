void setup() {
  // put your setup code here, to run once:
  DDRC = 0x3F; //아웃풋 모드
  PORTC = 0x00;
  TCCR1A = 0x03;
  TCCR1B = 0x0B;
  TCNT1 = 399;
  OCR1A = 574;
  TIMSK1 = 0x03;

}


unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int ovf_count = 0;

void loop() {
  // put your main code here, to run repeatedly:
//      unsigned long currentMillis = millis();
//      if(currentMillis - previousMillis > 20)
//      {
//        previousMillis = currentMillis;
//        OCR1A+=5;
//        if(OCR1A >= 974)
//        {
//          OCR1A = 574;
//        }
//      }
//  

}

SIGNAL(TIMER1_OVF_vect)
{
  TCNT1 =  399;
  ovf_count++;
  if(ovf_count == 8)
  {
    ovf_count = 0;
  }

  if(ovf_count == 0)
  {
    OCR1A = 974;
    PORTC |= 0x01;
  }
  else if(ovf_count == 1)
  {
    PORTC |= 0x02;
  }
  else if(ovf_count == 7)
  {
    OCR1A = 574;
  }

  
}


SIGNAL(TIMER1_COMPA_vect)
{
  if(ovf_count == 0)
  {
    PORTC &= ~0x01;
  }
  else if(ovf_count == 1)
  {
    PORTC &= ~0x02;
  }
}

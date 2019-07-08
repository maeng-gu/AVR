void setup() {
  // put your setup code here, to run once:
  DDRB = 0x20; //아웃풋 모드
  TCCR1A = 0x03;
  TCCR1B = 0x0B;
  TCNT1 = 524;
  OCR1A = 574;
  TIMSK1 = 0x03;

}


unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count;

void loop() {
  // put your main code here, to run repeatedly:
      unsigned long currentMillis = millis();
      if(currentMillis - previousMillis > 10)
      {
        previousMillis = currentMillis;
        OCR1A+=5;
        if(OCR1A >= 1020)
        {
          OCR1A = 524;
        }
      }
  

}

SIGNAL(TIMER1_OVF_vect)
{
  TCNT1 =  524;
  PORTB = 0x20;

  
}


SIGNAL(TIMER1_COMPA_vect)
{
  PORTB = 0x00;
}

//fast pwm
 void setup() {
  DDRB = 0x20; //아웃풋모드
  TCCR2A = 0x00;
  TCCR2B = 0x02;
  TCNT2 = 192;
  TIMSK2 = 0x01;

}

unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count;
int duty = 72;
int var = 32;
  
   SIGNAL(TIMER2_OVF_vect) {
    TCNT2 = 192;

    count++;
    if(count == 625)
    {
      count = 0;
      PORTB = 0x20;
    }
    else if(count == duty)
    {
      PORTB = 0x00;
    }


   }

    SIGNAL(TIMER1_COMPA_vect) {
    }

    
   void loop()
   {
    unsigned long currentMicros = micros();
    unsigned long currentMillis = millis();

    

    if(currentMillis - previousMillis > 20)
    {
      previousMillis = currentMillis;
      duty++;
      if(duty >= 72)
      {
        duty = 22;
      }
    }
    }

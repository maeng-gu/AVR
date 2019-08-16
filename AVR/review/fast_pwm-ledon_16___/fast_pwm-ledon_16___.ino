//fast pwm
 void setup() {
  DDRB = 0x20; //아웃풋모드
  TCCR1A = 0x03;
  TCCR1B = 0x0b;
  TCNT1 = 524; //16비트
  OCR1A = 574;
  TIMSK1 = 0x03;

}

unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count, duty;
int var = 32;
  
   SIGNAL(TIMER1_OVF_vect) {
    TCNT1 = 524;
    PORTB = 0x20;

    OCR2A = duty;

   }

    SIGNAL(TIMER1_COMPA_vect) {
      PORTB = 0x00;
    }

    
   void loop()
   {
    unsigned long currentMicros = micros();
    unsigned long currentMillis = millis();

    

    if(currentMillis - previousMillis > 100)
    {
      previousMillis = currentMillis;
      duty++;
      if(duty == 1024)
      {
        duty = 0;
      }
    }
    }

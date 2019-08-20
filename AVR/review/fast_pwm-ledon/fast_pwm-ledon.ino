//fast pwm
 void setup() {
  DDRB = 0x20; //아웃풋모드
  TCCR2A = 0x03;
  TCCR2B = 0x05;
  TCNT2 = 6;
  OCR2A = 25+6;
  TIMSK2 = 0x03;

}

unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count, duty;
int var = 32;
  
   SIGNAL(TIMER2_OVF_vect) {
    TCNT2 = 6;
    PORTB = 0x20;

    OCR2A = duty;

   }

    SIGNAL(TIMER2_COMPA_vect) {
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
      if(duty == 255)
      {
        duty = 6;
      }
    }
    }

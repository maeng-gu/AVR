//ctc모드
 void setup() {
  DDRB = 0x20; //아웃풋모드
  TCCR2A = 0x02;
  TCCR2B = 0x02;
  TCNT2 = 0;
  OCR2A = 200;
  TIMSK2 = 0x02;

}

unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count, duty;
  
   SIGNAL(TIMER2_COMPA_vect) {
    //previousMicros = currentMicros; 

    count++;
  
      if(count == 100){
        PORTB = 0x20;
        count = 0;
      }
      else if(count == duty)
      {
        PORTB = 0x00;
      }

   }
   
   void loop()
   {
    unsigned long currentMicros = micros();
    unsigned long currentMillis = millis();

    

    if(currentMillis - previousMillis > 100)
    {
      previousMillis = currentMillis;
      duty++;
      if(duty == 100)
      {
        duty = 0;
      }
    }
    }

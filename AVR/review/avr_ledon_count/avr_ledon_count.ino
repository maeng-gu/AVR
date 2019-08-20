
 void setup() {
  DDRB = 0x20; //아웃풋모드
  TCCR2A = 0x00;
  TCCR2B = 0x02;
  TCNT2 = 56;//200개 맞추기위하여
  TIMSK2 = 0x01;
}

unsigned long previousMicros = 0;
unsigned long currentMicros = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int count, duty;
  
   SIGNAL(TIMER2_OVF_vect) {
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
   }
  

//  PORTA = 0x20;
//  delay(1000);
//  PORTA = 0x00;
//  delay(1000);
  
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


void loop() {
  
  unsigned long currentMicros = micros();
  unsigned long currentMillis = millis();
   
   if(currentMicros - previousMicros > 100) { 
    previousMicros = currentMicros; 

    count++;
  
      if(count == 100){
        PORTB = 0x20;
        count = 0;
      }
      else if(count == duty)
      {
        PORTB = 0x00;
      }

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
  
}

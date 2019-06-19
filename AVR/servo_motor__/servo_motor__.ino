void setup() {
  //attachInterrupt(0, myISR, change);
  //10미리 주기로 100마이크로
  
  DDRB = 0x20; //pin D에 있는 것을 모두 output모드로 // pb5번 //led

  TCCR2A = 0x00;
  TCCR2B = 0x02; //타이머 fpwltmxj
  
  TCNT2 = 192; 


  TIMSK2 = 0x01; //timer conunt

  Serial.begin(9600);
  
}

void loop() {

}

  int count = 0;
  int duty = 12;


SIGNAL(TIMER2_OVF_vect)
{
  count++;
  TCNT2 = 192;
  
  if(count == 625)
  {
      PORTB = 0x20;
      count = 0;
      
         if(duty == 72)
         {
            duty = 12;
          }
         duty++;
         
  }

  if(count == duty) //72 22
  {
    
    
    PORTB = 0x00;
  }
  
}

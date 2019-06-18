void setup() {
  //attachInterrupt(0, myISR, change);
  //10미리 주기로 100마이크로
  
  DDRB = 0x20; //pin D에 있는 것을 모두 output모드로 // pb5번 //led

  TCCR2A = 0x00;
  TCCR2B = 0x02; //타이머 fpwltmxj

  TIMSK2 = 0x01; //timer conunt

  TCNT2 = 56; //4마이크로마다 1증
  Serial.begin(9600);
  
}

void loop() {

}

  int toggle = 0;
  int count = 0;


SIGNAL(TIMER2_OVF_vect)
{
  count++;
  TCNT2 = 56;
  
  if(count == 200)
  {
    count = 0;
    if(toggle == 0)
    {
      PORTB = 0x20;
      toggle = 1;
    }
    else
    {
      PORTB = 0x00;
      toggle = 0;
    }
  }
    
}

void setup() {
  //attachInterrupt(0, myISR, change);
  
  DDRD = 0x00; //pin D에 있는 것을 모두 input으로 사용한다. on 하면 자동초기화
  //0x01 write 0x00 read //pin map 참고
  
  EICRA = 0x01; //change때 interrupt를 건다.p74 //인터럽트 설정 //
  
  EIMSK = 0x01; //몇번 pin으로 interript를 
  Serial.begin(9600);
  
}

void loop() {

}

unsigned long in, out;

SIGNAL(INT0_vect) //int0 함수
{
  char input = PIND;
  
  if(input & 0x04) //pull up -> 띄웠을때
  {
    in = millis();
    Serial.println(in - out);
  }
  else
  {
    out = millis();
  }
  
}

// 누른시간 저장 후 출력
unsigned long in, out;
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0, myISR, CHANGE);
  Serial.begin(9600);

  //pinMode(3, output);
  //13번 pb5번
  DDRB = 0x20;

  DDRD = 0x00; // input

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //PIND => input -> 실시간으로 업데이트 된다. -> 8비트
  if(PIND & 0x04)
  {
      PORTB = 0x20;
  }
  else
  {
      PORTB = 0x00;
  }
  delay(100);
  /*
  //digitalWrite(13, HIGH);
  PORTB = 0x20;
  delay(1000);
  //digitalWrite(13, LOW);
  PORTB = 0x00;
  delay(1000);
  */

}

void myISR()
{
  if(digitalRead(2) == 0)
  {
    in = millis();
  }
  else
  {
    out = millis();
    Serial.println(out - in);
  }
}

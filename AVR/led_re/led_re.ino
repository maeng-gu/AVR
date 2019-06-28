void setup() {
  // put your setup code here, to run once:
  TCCR1A = 0x03; //a에 모드
  TCCR1B = 0x0D; //분주 8분주 <-외부에서 들어오는 16메가 헤르츠-< 외부 크리스탈 진동신호 -> 2메가 헤르츠 -> 0.5마이크로 -> 한 주기 -> 256부터 오버플로어 인터럽트가 걸림
  TCNT1 = 712;
  OCR1A = 11+712; // (7 ~ 256)
  //OCR2A = 36+712; //왼
  TIMSK1 = 0x03; //타이머마스크 인터럽트 -> 인터럽트 활성화
}

unsigned long previousMicors = 0; 
unsigned long previousMillis = 0; 
int count = 0;
int flag = 0;
int duty = 1000;
int ocrcount = 6;

SIGNAL(TIMER2_COMPA_vect)
{
  digitalWrite(13, 0);
}

SIGNAL(TIMER2_OVF_vect)
{
  TCNT1 = 6;
  digitalWrite(13, 1);
}

////fastpwm mode
////  TCCR2A = 0x03; //a에 모드
////  TCCR2B = 0x05; //분주 8분주 <-외부에서 들어오는 16메가 헤르츠-< 외부 크리스탈 진동신호 -> 2메가 헤르츠 -> 0.5마이크로 -> 한 주기 -> 256부터 오버플로어 인터럽트가 걸림
////  TCNT2 = 6;
////  OCR2A = 69; // (7 ~ 256)
////  TIMSK2 = 0x03; //타이머마스크 인터럽트 -> 인터럽트 활성화
//SIGNAL(TIMER2_COMPA_vect)
//{
//  digitalWrite(13, 0);
//}
//
//SIGNAL(TIMER2_OVF_vect)
//{
//  TCNT2 = 6;
//  digitalWrite(13, 1);
//}



//ctc모드
//SIGNAL(TIMER2_COMPA_vect)
//{
//  count++;
//  if(count == 100)
//  {
//    count = 0;
//    digitalWrite(13, 1);
//  }
//  if(count ==25)
//  {
//    digitalWrite(13, 0);
//  }
////  TCCR2A = 0x02; //a에 모드
////  TCCR2B = 0x02; //분주 8분주 <-외부에서 들어오는 16메가 헤르츠-< 외부 크리스탈 진동신호 -> 2메가 헤르츠 -> 0.5마이크로 -> 한 주기 -> 256부터 오버플로어 인터럽트가 걸림
////  OCR2A = 200;
////  TIMSK2 = 0x02; //타이머마스크 인터럽트 -> 인터럽트 활성화  TCCR2A = 0x02; //a에 모드
////  TCCR2B = 0x02; //분주 8분주 <-외부에서 들어오는 16메가 헤르츠-< 외부 크리스탈 진동신호 -> 2메가 헤르츠 -> 0.5마이크로 -> 한 주기 -> 256부터 오버플로어 인터럽트가 걸림
////  OCR2A = 200;
////  TIMSK2 = 0x02; //타이머마스크 인터럽트 -> 인터럽트 활성화
//}

//노멀모드
//SIGNAL(TIMER2_OVF_vect)
//{
//  TCNT2 = 56;
//  count++;
//  if(coumt == 100)
//  {
//    count = 0;
//    digitalWrite(13,1);
//  }
//
//  if(count == 25)
//  {
//    digitalWrite(13,0);
//  }
//}



void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > 10)
  {
    previousMillis - currentMillis;
    ocrcount++;
    if(ocrcount == 10)
    {
      ocrcount = 6;
    }
    OCR2A = ocrcount;
  }
}

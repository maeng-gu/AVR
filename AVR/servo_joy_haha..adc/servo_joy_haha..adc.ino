void setup() {
  Serial.begin(9600);

  DDRB = 0x03;
  PORTB = 0X00;

  TCCR1A = 0X03;
  TCCR1B = 0X0A;
  TCCR1C = 0X00;
  TCNT1 = 1024 - 400;
  TIMSK1= 0X01;

}

int servo_var = 22;
int servo_var_1 = 22;
int adc_value_x;
int adc_value_y;
int count;

//2,5m
//25u = 40KHZ
//16MHZ /= 400

//400
//1023 OVF
//623 400


void loop() {
  // put your main code here, to run repeatedly:

  ADMUX = 0x40;
  ADCSRA = 0x87;
  ADCSRA |= 0x40;

  adc_value_x = ADC;

  while(ADCSRA & 0x40);
  
  ADMUX = 0x41;
  ADCSRA = 0x87;
  ADCSRA |= 0x40;

  adc_value_y = ADC;

  if(adc_value_x > 700 && adc_value_x < 1024)
  {
    servo_var = 75;
    Serial.println("72");
  }
  else if (adc_value_x >= 0 && adc_value_x < 400)
  {
    servo_var = 20;
    Serial.println("22");
  }

  
  if(adc_value_y > 700 && adc_value_y < 1024)
  {
    servo_var_1 = 75;
    Serial.println("~68");
  }
  else if (adc_value_y >= 0 && adc_value_y < 400)
  {
    servo_var_1 = 20;
    Serial.println("~36");
  }


  delay(10);
}

int over_f = 0; //36 ~ 680
int x = 0;

SIGNAL(TIMER1_OVF_vect)
{
    TCNT1 = 1024 - 40;

    over_f++;

    if(over_f > 100)
    {
      over_f = 0;
      x++;
      if (x >= 8) x = 0;

      if (x == 0) PORTB |= 1;
      if (x == 1) PORTB |= 2;
    }
    else if (over_f > servo_var_1 && x == 0)
    {
      PORTB &= ~1;
    }
    else if (over_f > servo_var && x == 1)
    {
      PORTB &= ~2;
    }

    
    
    //Serial.println("timer in");
    /*
    
    count++;
    if(count == 625)
    {
      count = 0;
      PORTB |= 0x01;
      //Serial.println("timer 0");
    }
    else if(count == servo_var) //72멘 오른쪽, 22멘 왼쪽
    {
      PORTB &= ~0x01;
      Serial.println(servo_var);
    }*/
}

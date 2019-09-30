void setup() {
  Serial.begin(9600);
}

int adc_value_x;
int adc_value_y;

void loop() {
//  ADMUX = 0x40;
//  ADCSRA = 0x87;
//  ADCSRA |= 0x40;
//
//  adc_value_x = ADC;
//
//  while(ADCSRA & 0x40);
//  
//  ADMUX = 0x41;
//  ADCSRA = 0x87;
//  ADCSRA |= 0x40;
//
//  adc_value_y = ADC;


  adc_value_x = analog_R(A0);
  adc_value_y = analog_R(A1);
  
  Serial.println(adc_value_x);
  Serial.println(adc_value_y);
  Serial.println();
  delay(10);

}

int analog_R(int pin)
{
  ADMUX = 0x40 | (pin - A0);
  ADCSRA = 0x87;
  ADCSRA |= 0x40;

  adc_value_x = ADC;

  while(ADCSRA & 0x40);

  return adc_value_x;

}

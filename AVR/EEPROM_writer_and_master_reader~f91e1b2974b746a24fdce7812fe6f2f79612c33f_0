void setup() {
  DDRC = 0x30; //4:SDA, 5:SCL
  PORTC = 0x10;//SDA
  PORTC |= 0x20;//SCL

  Serial.begin(9600);
}

int i;

void ack() {
  DDRC &= ~0x10;
  delay(1);
  PORTC |= 0x20;    //clock HIGH
  Serial.println(PINC & 0x10);
  delay(1);
  PORTC &= ~0x20;   //clock LOW
  //data pin output
  delay(1);
  DDRC |= 0x10;
}

void get_8bit(char a) {
  for (i = 0; i < 8; i++) {
    if (a & (0x80 >> i))
      PORTC |= 0x10;
    else
      PORTC &= ~0x10;

    delay(1);
    PORTC |= 0x20;
    delay(1);
    PORTC &= ~0x20;
  }
}

void loop() {
  //start
  PORTC &= ~0x10;
  //stand by
  PORTC &= ~0x20;

  //device id
  get_8bit(0xA0);
  ack();

  //memory address
  get_8bit(0x00);
  ack();
  //data
  get_8bit(0x33);
  ack();

  //stop
  PORTC &= ~0x10;  //SDA LOW
  PORTC |= 0x20;    //SCL HIGH
  PORTC |= 0x10;    //SDA HIGH

  delay(2500);
}

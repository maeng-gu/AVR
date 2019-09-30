void setup() {
  DDRC = 0x30; //4:SDA. 5 : SCL output mode
  PORTC = 0x10; //SDA
  PORTC |= 0x20; //SCL
  delay(1);
  
  Serial.begin(9600);
}

void loop() {
  // start
  PORTC &= ~0x10;
  delay(1);
  //stand by
  PORTC &= ~0x20;
  delay(1);
  //device address
  //1010 000 *0 W*
  //0xA0 - ox80(1000 0000)
  for (int i = 0 ; i < 8 ; i++)
  {
    if (0xA0 & (0x80 >> i))
    {
      PORTC |= 0x10;
    }
    else
    {
      PORTC &= ~0x10; //clear
    }

    delay(1);
    PORTC |= 0x20;
    delay(1);
    PORTC &= ~0x20;
    delay(1);
    
  }

 /////////ack/////////
  //data pin input
  DDRC &= ~0x10;

  delay(1);
  PORTC |= 0x20; //clock high
  Serial.println(PINC & 0x10);

  delay(1);
  PORTC &= ~0x20; //clokc low

  delay(1);
  //daia pin output
  DDRC |= 0x10;
/////////////////////////

  //memory address
  for (int i = 0 ; i < 8 ; i++)
  {
    if (0x00 & (0x80 >> i))
    {
      PORTC |= 0x10;
    }
    else
    {
      PORTC &= ~0x10; //clear
    }

    delay(1);
    PORTC |= 0x20;
    delay(1);
    PORTC &= ~0x20;
    delay(1);
  }


 /////////ack/////////
  //data pin input
  DDRC &= ~0x10;

  PORTC |= 0x20; //clock high
  Serial.println(PINC & 0x10);

  delay(1);
  PORTC &= ~0x20; //clokc low
  delay(1);
  //daia pin output
  DDRC |= 0x10;
/////////////////////////
  //data
  for (int i = 0 ; i < 8 ; i++)
  {
    if (0x31 & (0x80 >> i))
    {
      PORTC |= 0x10;
    }
    else
    {
      PORTC &= ~0x10; //clear
    }
 
    delay(1);
    PORTC |= 0x20;
    delay(1);
    PORTC &= ~0x20;
    delay(1);
  }

 /////////ack/////////
  //data pin input
  DDRC &= ~0x10;
  
  PORTC |= 0x20; //clock high
  Serial.println(PINC & 0x10);

  delay(1);
  PORTC &= ~0x20; //clokc low

  delay(1);
  //daia pin output
  DDRC |= 0x10;
/////////////////////////

  delay(1);
  //stop
  PORTC &= 0x10; //SDA LOW
    delay(1);
  PORTC |= 0x20; //SCL HIGH
  delay(1);
  PORTC |= 0x10; // SDA HIGH

    
  Serial.println("ok");

  delay(5000);
}

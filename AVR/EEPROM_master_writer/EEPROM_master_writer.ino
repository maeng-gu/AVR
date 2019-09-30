// Wire Master Writer


#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  Wire.beginTransmission(0x50); // transmit to device #8
  Wire.write(0x00);        // sends five bytes
  
  for(int i = 0 ; i < 8 ; i++)
  {
    Wire.write('1'+i);
  }
  
  Wire.endTransmission();    // stop transmitting

  delay(500);

}

#include <Wire.h>

void ir_init() {
  Wire.begin();
  // Begin I2C as a master
}

int read_ir() {
  char ball_dir;
  char ball_tx;

  Wire.beginTransmission(0x01);
  // device address is specified in datasheet
  Wire.write(8);             // sends value byte
  Wire.endTransmission();     // stop transmitting

  Wire.requestFrom(0x01, 1);    // reques 1 bytes from slave device 0x01
  while (Wire.available())   // slave may send less than requested
  {
    ball_dir = Wire.read();    // receive a byte as character
  }

  Wire.beginTransmission(0x01);
  // device address is specified in datasheet
  Wire.write(ball_dir);             // sends value byte
  Wire.endTransmission();     // stop transmitting

  Wire.requestFrom(0x01, 1);    // request 6 bytes from slave device #2
  while (Wire.available())   // slave may send less than requested
  {
    ball_tx = Wire.read();    // receive a byte as character
  }

  Serial.print(ball_dir, DEC);         // print the character
  Serial.print("\t");         // print the character
  Serial.println(ball_tx, DEC);         // print the character

  return ball_dir;
}

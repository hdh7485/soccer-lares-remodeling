#ifndef IR_H
#define IR_H

#include <Wire.h>

#define TCAADDR 0x70

class IR {
  private:
    char ball_dir_front;
    char ball_tx_front;

    char ball_dir_behind;
    char ball_tx_behind;

  public:
    char ball_tx;
    char ball_dir;

    IR() {
      Wire.begin();
    }

    void tcaselect(uint8_t i) {
      if (i > 7) return;

      Wire.beginTransmission(TCAADDR);
      Wire.write(1 << i);
      Wire.endTransmission();
    }

    void read_ir(byte i2c_id = 0x01) {
      tcaselect(0);

      Wire.beginTransmission(i2c_id);
      // device address is specified in datasheet
      Wire.write(8);             // sends value byte
      Wire.endTransmission();     // stop transmitting

      Wire.requestFrom(i2c_id, 0x01);    // reques 1 bytes from slave device 0x01
      while (Wire.available())   // slave may send less than requested
      {
        ball_dir_front = Wire.read();    // receive a byte as character
      }

      Wire.beginTransmission(i2c_id);
      Wire.write(ball_dir_front);             // sends value byte
      Wire.endTransmission();     // stop transmitting

      Wire.requestFrom(i2c_id, 0x01);    // request 6 bytes from slave device #2
      while (Wire.available())   // slave may send less than requested
      {
        ball_tx_front = Wire.read();    // receive a byte as character
      }

      tcaselect(1);

      Wire.beginTransmission(i2c_id);
      // device address is specified in datasheet
      Wire.write(8);             // sends value byte
      Wire.endTransmission();     // stop transmitting

      Wire.requestFrom(i2c_id, 0x01);    // reques 1 bytes from slave device 0x01
      while (Wire.available())   // slave may send less than requested
      {
        ball_dir_behind = Wire.read();    // receive a byte as character
      }

      Wire.beginTransmission(i2c_id);
      Wire.write(ball_dir_behind);             // sends value byte
      Wire.endTransmission();     // stop transmitting

      Wire.requestFrom(i2c_id, 0x01);    // request 6 bytes from slave device #2
      while (Wire.available())   // slave may send less than requested
      {
        ball_tx_behind = Wire.read();    // receive a byte as character
      }

      if (ball_tx_front > ball_tx_behind) {
        ball_tx = ball_tx_front;
        ball_dir = - ball_dir_front + 4;
        if (ball_dir < 0) {
          ball_dir += 12;
        }
      }
      else {
        ball_tx = ball_tx_behind;
        ball_dir = ball_dir_behind + 2;
      }

#ifdef DEBUG
      Serial.print(ball_dir_front, DEC);         // print the character
      Serial.print("\t");         // print the character
      Serial.print(ball_tx_front, DEC);         // print the character
      Serial.print("\t");         // print the character
      Serial.print(ball_dir_behind, DEC);         // print the character
      Serial.print("\t");         // print the character
      Serial.print(ball_tx_behind, DEC);         // print the character
      Serial.print("\t");         // print the character
      Serial.print(ball_dir, DEC);         // print the character
      Serial.print("\t");         // print the character
      Serial.print(ball_tx, DEC);         // print the character
      Serial.print("\n");         // print the character
#endif
    }
};


#endif

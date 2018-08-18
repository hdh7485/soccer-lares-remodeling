//#define DEBUG

#include "line.h"
#include "ir.h"
//#include "compass.h"

char dir = 0;

IR ir_sensor;

void setup() {
  motor_init();
  Serial.begin(115200);
}

void loop() {
  ir_sensor.read_ir();
  Serial.println(ir_sensor.ball_tx, DEC);
  Serial.println(ir_sensor.ball_dir, DEC);
  for (int i = 0; i < 100; i++) {
    motor_drive(i, -i, i, i);
    delay(50);
  }
//  
//  for (int i = 30; i > 0; i--) {
//    motor_drive(-i, i, i, -i);
//    delay(50);
//  }
  //dir = read_ir();
  //following_ball(dir, 40);


  /*for (int i = -100; i < 100; i++) {
    motor_drive(i, i, i, i);
    delay(50);
    Serial.println(i);
    }
    for (int i = 100; i > -100; i--) {
    motor_drive(i, i, i, i);
    delay(50);
    Serial.println(i);
    }*/

  //motor_drive(-10, -10, 10, 10);
  //read_compass();
  //  read_ultra();
  //  read_light();
  //dir_move(0, 10);

}


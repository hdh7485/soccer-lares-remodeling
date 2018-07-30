#define DEBUG

#include "motor.h"
#include "IR.h"
#include "compass.h"

char dir = 0;


void setup() {
  motor_init();
  ir_init();
  compass_init();
  Serial.begin(115200);
}

void loop() {

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
  read_ir();
  read_compass();
  //angle_move(360, 30);
}


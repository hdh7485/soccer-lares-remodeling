#define DEBUG

#include "line.h"
#include "ir.h"
//#include "compass.h"

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

  //motor_drive(-10, -10, 10, 10);
  read_ir();
  //read_compass();
  read_ultra();
  read_light();
  //dir_move(0, 10);
  
}


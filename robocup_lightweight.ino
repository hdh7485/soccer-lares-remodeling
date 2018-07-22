#include "motor.h"
#include "IR.h"


char dir = 0;

void setup() {
  motor_init();
  ir_init();
  Serial.begin(9600);
}

void loop() {
  
  dir = read_ir();
  following_ball(dir, 40);
  
  /*
  for (int i = -100; i < 100; i++) {
    motor_drive(i, i, i, i);
    delay(50);
    Serial.println(i);
  }
  for (int i = 100; i > -100; i--) {
    motor_drive(i, i, i, i);
    delay(50);
    Serial.println(i);
  }
  */
}

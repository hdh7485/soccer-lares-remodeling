#ifndef MOTOR_H
#define MOTOR_H

#include "compass.h"

#define KP 1

void motor_init() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
}

void motorA(int power) {                                                 //FL
  int dir;
  int power_result;

  if (power < 0)
  {
    dir = LOW;
    power_result = -(power * 255) / 100;
  }
  else if (power > 0)
  {
    dir = HIGH;
    power_result = 255 - ((power * 255) / 100);
  }
  else
  {
    dir = 0;
    power_result = 0;
  }
  digitalWrite(26, dir);
  analogWrite(3, power_result);
}

void motorB(int power) {                                                 //BL
  int dir;
  int power_result;

  if (power < 0)
  {
    dir = LOW;
    power_result = -(power * 255) / 100;
  }
  else if (power > 0)
  {
    dir = HIGH;
    power_result = 255 - ((power * 255) / 100);
  }
  else
  {
    dir = 0;
    power_result = 0;
  }
  digitalWrite(28, dir);
  analogWrite(5, power_result);
}

void motorC(int power) {                                                 //BL
  int dir;
  int power_result;

  if (power < 0)
  {
    dir = LOW;
    power_result = -(power * 255) / 100;
  }
  else if (power > 0)
  {
    dir = HIGH;
    power_result = 255 - ((power * 255) / 100);
  }
  else
  {
    dir = 0;
    power_result = 0;
  }
  digitalWrite(24, dir);
  analogWrite(6, power_result);
}

void motorD(int power) {                                                 //BR
  int dir;
  int power_result;

  if (power < 0)
  {
    dir = LOW;
    power_result = -(power * 255) / 100;
  }
  else if (power > 0)
  {
    dir = HIGH;
    power_result = 255 - ((power * 255) / 100);
  }
  else
  {
    dir = 0;
    power_result = 0;
  }
  digitalWrite(22, dir);
  analogWrite(9, power_result);
}

void motor_drive(int ma, int mb, int mc, int md) {
  motorA(ma);
  motorB(mb);
  motorC(mc);
  motorD(md);
}

void x_move(int power) {
  motorA(-power);
  motorB(power);
  motorC(power);
  motorD(-power);
}

void dir_move(float degree, int power) {
  const float pi = 3.14;
  int x_power = cos(degree / 180 * pi);
  int y_power = sin(degree / 180 * pi);
}

void compass_move(int ma, int mb, int mc, int md)
{
  int comp;
  //read_compass();
  //  comp = (int)compass / 10;
  comp = read_compass();
  comp = comp - 180;
  if (comp > 100)
  {
    motor_drive(5, 5, 5, 5);
  }
  else if (comp < -100)
  {
    motor_drive(-5, -5, -5, -5);
  }
  else
  {
    motor_drive(ma + comp * KP, mb + comp * KP, mc + comp * KP, md + comp * KP);
  }
}

void compass_dir_move(int angle, int power)
{
  switch (angle)
  {
    case 0:
      compass_move(-power, -power, power, power);
      break;
    case 1:
      compass_move(-power, 0, power, 0);
      break;
    case 2:
      compass_move(-power, power, power, -power);
      break;
    case 3:
      compass_move(0, power, 0, -power);
      break;
    case 4:
      compass_move(power, power, -power, -power);
      break;
    case 5:
      compass_move(power, 0, -power, 0);
      break;
    case 6:
      compass_move(power, -power, -power, power);
      break;
    case 7:
      compass_move(0, -power, 0, power);
      break;
  }
  /*case 8:
     compass_move(0, -power, power);
     break;
    case 9:
     compass_move(power / 2, - power, power / 2);
     break;
    case 10:
     compass_move(power, -power, 0);
     break;
    case 11:
     compass_move(power, -power / 2, -power / 2);
     break;
    }*/

  /*if(angle <= 90){
    compass_move(-power, -power + (power * 2 / 90) * angle, power, power - (power * 2 / 90) * angle);
    }
    else if(angle > 90 && angle <= 180){
    compass_move(-power + (power * 2 / 90) * (angle - 90), power, power - (power * 2 / 90) * (angle - 90), -power);
    }
    else if(angle > 180 && angle <= 270){
    compass_move(power, power - (power * 2 / 90) * (angle - 180), -power, -power + (power * 2 / 90) * (angle - 180));
    }
    else if(angle > 270 && angle <= 360){
    compass_move(power - (power * 2 / 90) * (angle - 270), -power, -power + (power * 2 / 90) * (angle - 270), power);
    }*/
}

#endif

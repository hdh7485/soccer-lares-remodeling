void motor_init() {
  for (int i = 2; i < 9; i++)
    pinMode(i, OUTPUT);
}

void motorA(int power) {
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
  digitalWrite(2, dir); //FL
  analogWrite(3, power_result);
}

void motorB(int power) {
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
  digitalWrite(4, dir); //BL
  analogWrite(5, power_result);
}

void motorC(int power) {
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
  digitalWrite(7, dir); //BR
  analogWrite(6, power_result);
}

void motorD(int power) {
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
  digitalWrite(8, dir); //FR
  analogWrite(9, power_result);
}

void motor_drive(int ma, int mb, int mc, int md) {
  motorA(ma);
  motorB(mb);
  motorC(mc);
  motorD(md);
}

void following_ball(int dir, int power) {
  switch (dir) {
    case 1:
      motor_drive(-power, -power, -power, -power);
      break;
    case 2:
      motor_drive(-power, -power, -power, -power);
      break;
    case 3:
      motor_drive(-power/2, -power/2, -power/2, -power/2);
      break;
    case 4:
      motor_drive(0, 0, 0, 0);
      break;
    case 5:
      motor_drive(power/2, power/2, power/2, power/2);
      break;
    case 6:
      motor_drive(power, power, power, power);
      break;
    case 7:
      motor_drive(power, power, power, power);
      break;
    default:
      motor_drive(0, 0, 0, 0);
  }
}

void angle_move(int a, int p){
  if(a <= 90){
    motor_drive(-p, -p + (p * 2 / 90) * a, p, p - (p * 2 / 90) * a);
  }
  else if(a > 90 && a <= 180){
    motor_drive(-p + (p * 2 / 90) * (a - 90), p, p - (p * 2 / 90) * (a - 90), -p);
  }
  else if(a > 180 && a <= 270){
    motor_drive(p, p - (p * 2 / 90) * (a - 180), -p, -p + (p * 2 / 90) * (a - 180));
  }
  else if(a > 270 && a <= 360){
     motor_drive(p - (p * 2 / 90) * (a - 270), -p, -p + (p * 2 / 90) * (a - 270), p);
  }
}

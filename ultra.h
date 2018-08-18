#ifndef ULTRA_H
#define ULTRA_H

int ultra[4] = {
   analogRead(A0),
   analogRead(A1),
   analogRead(A2),
   analogRead(A3)
  };


void ultra_init() {
  Serial.begin(9600);
}

void read_ultra() {
  int ultra[4] = {
   analogRead(A0),
   analogRead(A1),
   analogRead(A2),
   analogRead(A3)
  };
  
  #ifdef DEBUG
  Serial.print("ultra");
  Serial.print("\t");
  Serial.print("Front: ");
  Serial.print(ultra[0]);
  Serial.print(" Right: ");
  Serial.print(ultra[1]);
  Serial.print(" Behind: ");
  Serial.print(ultra[2]);
  Serial.print(" Left: ");
  Serial.print(ultra[3]);
  Serial.print("\n");
#endif
}

#endif

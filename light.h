#ifndef LIGHT_H
#define LIGHT_H

int light[4] = {
   analogRead(A4),
   analogRead(A5),
   analogRead(A6),
   analogRead(A7)
   };


void light_init() {
  Serial.begin(9600);
}

void read_light() {
  int light[4] = {
   analogRead(A4),
   analogRead(A5),
   analogRead(A6),
   analogRead(A7)
  };
  
  #ifdef DEBUG
  Serial.print("light");
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

/*void light (int l) {
  if(l == 0)
  {
    return light[0];
  }
  else if(l == 1)
  {
    return light[1];
  }
  else if(l == 2)
  {
    return light[2];
  }
  else if(l == 3)
  {
    return light[3];
  }
}*/

#endif

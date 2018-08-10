#include <Wire.h> //I2C Arduino Library

void compass_init() {
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(0x1E); //start talking
  Wire.write(0x02); // Set the Register
  Wire.write(0x00); // Tell the HMC5883 to Continuously Measure
  Wire.endTransmission();
}

float calculate_heading(int x, int y){
  float heading = atan2(y, x);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.22;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  return headingDegrees;
}

float read_compass() {
  int x, y, z; //triple axis data

  //Tell the HMC what regist to begin writing data into
  Wire.beginTransmission(0x1E);
  Wire.write(0x03); //start with register 3.
  Wire.endTransmission();


  //Read the data.. 2 bytes for each axis.. 6 total bytes
  Wire.requestFrom(0x1E, 6);
  if (6 <= Wire.available()) {
    x = Wire.read() << 8; //MSB  x
    x |= Wire.read(); //LSB  x
    z = Wire.read() << 8; //MSB  z
    z |= Wire.read(); //LSB z
    y = Wire.read() << 8; //MSB y
    y |= Wire.read(); //LSB y
  }

  // Show Values
#ifdef DEBUG
  Serial.print("X Value: ");
  Serial.print(x);
  Serial.print(" Y Value: ");
  Serial.print(y);
  Serial.print(" Z Value: ");
  Serial.print(z);
  Serial.print('\t');
  Serial.print("Heading (degrees): "); 
  Serial.print(calculate_heading(x, y));
  Serial.print('\n');
#endif
 return calculate_heading(x, y);
}


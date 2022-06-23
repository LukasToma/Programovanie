#include <Wire.h> //oznamujeme IDE, ze budeme pouzivat Wire library

void setup() {
  Serial.begin(9600);
  Wire.begin(); //spusti Wire library
  Wire.beginTransmission(0x00); //spusti prenos
}

void loop() {
  Wire.requestFrom(0x48,4); //precita 4 bytey z adresy 0x48
  float teplota = Wire.read(); //to co precita ulozi do premennej teplota
  Serial.print("Teplota je "); //vypis na COM
  Serial.print(teplota); ///vypise teplotu
  Serial.println(" stupnov Celsia.");
  delay(1000); //kazdu 1 sekundu
}

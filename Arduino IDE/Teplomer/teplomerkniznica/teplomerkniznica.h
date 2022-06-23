#include <Temperature_LM75_Derived.h>
Generic_LM75 temperature;

void start() {
  while(Serial.available()) {}  
  Serial.begin(9600);
  Wire.begin();
  Serial.println("LM75A Teplomer");
}

void teplota() {
  Serial.print("Teplota je ");
  Serial.print(temperature.readTemperatureC());
  Serial.println(" stupnov Celsia.");
  delay(500);
}

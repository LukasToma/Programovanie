const int led = 5;
const int photoResistor = A0;
int prValue; //photoresistor value
float calValue;
//float percent;
int minValue=10000;
int maxValue;
float input;
float inputVal;
float ledBrightness;
float sensorVal;

//pwm pin 5 a 6 na timer0
//pwm pin 9 a 10 na timer 1
//pwm pin 11 a 3 na timer 2

void setup() {
  Serial.begin(9600);  //zadat vacsi baud rate napriklad 250 000      //Printout
  pinMode(led,HIGH);
  calibration();
}

void loop() {
    sensorVal = sensorRead();
    actuatorWrite(sensorVal);
    delay(500);
  }


void calibration(){
    for (int i = 0; i <= 2; i++) {
    Serial.println("Prebieha kalibracia...");
  //zbehne prvych 5 sekund napriklad na kalibraciu minima a maxima
    prValue = analogRead(photoResistor);
    if (prValue<minValue) {
      minValue=prValue;
      }
    if (prValue>maxValue) {
      maxValue=prValue;
      } 


    digitalWrite(led,HIGH);
    delay(100);
  }
    Serial.print("Minimum = ");
    Serial.print(minValue);
    Serial.print(" Maximum = ");
    Serial.print(maxValue);
    Serial.println();
}
//void actuatorWrite(float){
void actuatorWrite(float input){
  //ovladanie ledky cez pwm signal, vstup 0 az 100%, teda 0 az 255
      
      input = int(input*100);
      ledBrightness = map(inputVal,0,10000,0,255);
      analogWrite(led,ledBrightness);
   }

float sensorRead(){
 //odcitavat hodnoty a dat to do percent
  //return
  prValue = analogRead(photoResistor);
  calValue = map(prValue,minValue, maxValue, 0, 10000);
  float percent = calValue/100.0;

  return percent;
}

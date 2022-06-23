#include <TimerOne.h>

//arduino for control engineers page cca 316

unsigned long int Ts=100;     //sample time
unsigned long int t;          //current time
unsigned long int prevTime;   //previous time
bool stepEnable = false;      //step flag

const int led = 5;
const int photoResistor = A0;
int prValue; //photoresistor value
float calValue;
float percent;
int minValue=10000; 
int maxValue=-10000;

void setup() {
  Serial.begin(9600);         //Printout
  Timer1.initialize(Ts*1000); // period in us
  Timer1.attachInterrupt(stepTimer);  //launch this
  pinMode(led,HIGH);
}

void loop() {
  t = millis();             //current time
  if (stepEnable) {         //if flag true
    prValue = analogRead(photoResistor);
    digitalWrite(led,HIGH);
    Serial.print(prValue);
    Serial.print(" ");
    Serial.print(percent);
    Serial.print("% ");
    step();                 //step
    printTime();            //print timing
    stepEnable = false;
  }

}

void step(void) {
  delay(50+random(50));
}

void printTime (void) {
  Serial.print(t);
  Serial.print("\t");
  Serial.println((float)(t-prevTime)/1000.0, 4);
  prevTime = t;
}

void stepTimer() {
  stepEnable = true;
}

void calibration() {
  if (prValue<minValue) {
    minValue==prValue;
  }
  if (prValue>maxValue) {
    maxValue==prValue;
  }
  
  calValue = map(prValue,0, 1023, minValue, maxValue);
  Serial.print(minValue);
  Serial.print(" je minimum ");
  Serial.print(maxValue);
  Serial.print(" je maximum ");
  
  percent = calValue/10.0;
}

void actuatorWrite(float){
  
}

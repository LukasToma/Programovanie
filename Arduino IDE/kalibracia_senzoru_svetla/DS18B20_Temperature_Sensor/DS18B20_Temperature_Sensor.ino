#include <OneWire.h>  //kniznice potrebne k fungovaniu
#include <DallasTemperature.h> 

const int busPin = 2; //definovanie Pinu na Arduine, cez ktory budeme nacitavat udaje z teplomera
float teplota; //premenna typu float s teplotou
unsigned long cas; //premenne unsigned long, kvoli velkosti ich maximalnej hodnoty
unsigned long start;
unsigned long sekundy;

OneWire myOneWire(busPin); //nacitanie Onewire Library
DallasTemperature tempSensor(&myOneWire); //nacitanie Dallas Temperature library

void setup() {
  Serial.begin(9600); //spustenie serialu s hodnotou 9600 baudov
  tempSensor.begin(); //spustenie Dallas Temperature kniznice
  start = millis(); //pocitanie casu od spustenia Arduina v milisekundach do premennej start
}

void loop() {
  cas = millis(); //pocitanie casu od spustenia Arduina v milisekundach do premennej cas
  if ((cas-start)>=1000) { //vypisovanie premennych kazdu 1 sekundu
    tempSensor.requestTemperatures(); //vypytanie casu z Dallas kniznice
    teplota = tempSensor.getTempCByIndex(0); //prekonvertovane do stupnov C
    Serial.print(teplota); //teplota v stupnoch C
    Serial.print("  ");
    sekundy = cas/1000; //vydelenie 1000 aby sme z milisekund dostali sekundy
    Serial.print(sekundy); //vypisanie casu v sekundach
    Serial.println();
    start = cas; //synchronizacia nasej premennej cas s casom od startu
    //ak by sme to sem nedali aktualizacia teploty by prebehla vzdy, ked cely kod Arduino spracuje
    //to je okolo 0.6 sekundy, my ale chceme aby sa to aktualizovalo kazdu 1 sekundu
    //casu aktualizacie pri tomto type vypisovania nemoze byt mensi ako cas vypoctu, teda tych cca 0.6 sekund
  }
}

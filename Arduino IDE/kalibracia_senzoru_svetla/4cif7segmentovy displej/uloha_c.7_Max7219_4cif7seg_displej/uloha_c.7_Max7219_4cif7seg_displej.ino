#include "LedControl.h" //  need the library

LedControl lc=LedControl(11,13,10,1); //Cisla na led control znamenaju: 
//MAX7219ENG Pin1 Din - Pin 11 na Arduine
//MAX7219ENG Pin12 LOAD(CS) - Pin 10 na Arduine
//MAX7219ENG Pin13 CLK - Pin13 na Arduine
//1 lebo pouzivame 1 MAX7219 chip

int displej0 = 0; //definovanie premennych na jednotlive cifry na displeji
int displej1 = 0;
int displej2 = 0;
int displej3 = 0;

void setup()
{
  Serial.begin(9600); //zacatie seriovej komunikacie
  Serial.println("Napiste pozadovane cislo v tvare: X X X X, napr. 1 2 3 4"); //vysvetlenie ako zadavat numericke hodnoty
  //0 je oznacenie MAX7219 Controlleru
  lc.shutdown(0,false);// zapnutie chipu, 0 je adresa chipu, ktora zacina 0, napr. keby su 2 chipy tak ich oznacime 
  lc.setIntensity(0,8);// jas displeja, od 0 do 15
  lc.clearDisplay(0);// vymazanie hodnot na displeji
}

void loop()
{
while (Serial.available()) {

    displej0 = Serial.parseInt(); //nacitanie cisla, kde to vzdy hlada dalsi integer
    displej1 = Serial.parseInt(); 
    displej2 = Serial.parseInt();
    displej3 = Serial.parseInt();

    if (Serial.read() == '\n') { //spusti sa ked stlacime enter
      lc.clearDisplay(0); //vymazanie hodnoty na displeji
      konzola(); //funkcia konzola, ktora sa postara o vypisanie 
  }
}
}
void konzola(){
      Serial.print("Displej = "); //vypisanie uzivatelom zadanych premennych do COMu
      Serial.print(displej0);
      Serial.print(displej1);
      Serial.print(displej2);
      Serial.print(displej3);
      Serial.println();

      chybovaHlaska(); //funkcia na vypisanie chybovej hlasky ak je zadana cifra menej ako 0 alebo viac ako 9
      
      displej0 = constrain(displej0, 0, 9); //obmedzenie zadanych hodnot kazdej cifry od 0 po 9
      displej1 = constrain(displej1, 0, 9);
      displej2 = constrain(displej2, 0, 9);
      displej3 = constrain(displej3, 0, 9);

      lc.setDigit(0,0,displej0,false); //nastavenie jednotlivych hodnot na displeji
      lc.setDigit(0,1,displej1,false);
      lc.setDigit(0,2,displej2,false);
      lc.setDigit(0,3,displej3,false); 
}

void chybovaHlaska(){ 
       if (displej0<0 || displej0>9) { //kontrolna podmienka ci je to od 0 do 9
        Serial.println("Cifra 1 nebola v rozsahu od 0 do 10!"); 
        }
       if (displej1<0 || displej1>9) {
          Serial.println("Cifra 2 nebola v rozsahu od 0 do 10!"); 
        }
       if (displej2<0 || displej2>9) {
          Serial.println("Cifra 3 nebola v rozsahu od 0 do 10!"); 
        }
       if (displej3<0 || displej3>9) {
          Serial.println("Cifra 4 nebola v rozsahu od 0 do 10!"); 
        } 
}

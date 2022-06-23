/* 4 Ciferny LED Displej - Piny:
 *  
      A=11
      ---
F=10 |   | B=7                Piny sluziace na rozsvietenie segmentu
     |G=5|
      ---
E=1  |   | C=4
     |   |  
      ---   . DP=3 
      D=2

     GND: Displej1=12         Piny urcene na rozsvietenie jednotliveho displeju z lava do prava
          Displej2=9          12 pre lavy displej
          Displej3=8          6 pre uplne pravy
          Displej4=6
          
Displej ma na Breadboarde 12 Pinov, idu od laveho spodneho rohu(Pin 1), proti smeru hodinovych ruciciek, vlavo hore je Pin 12
       
  Pin12 |||||| Pin7                 
|-------------------|
| 8     8     8    8|
|-------------------|
  Pin1  |||||| Pin6
 */
#include <ezButton.h>

#define LOOP_STATE_STOPPED 0 // ezButton library - vypnute tlacidlo
#define LOOP_STATE_STARTED 1 // ezButton library - zapnute tlacidlo

ezButton button(A0);  //pin A0 pre tlacidlo z ezButton library pre ulahcenie spravneho fungovania tlacidla
int loopState = LOOP_STATE_STOPPED; //zacneme s vypnutym tlacidlom

//Piny na Arduine a premenne pre jednotlive cifry na displeji
int disp1 = 9; 
int disp2 = 10; 
int disp3 = 11; 
int disp4 = 12; 
/*
Pin 12 z cifry č.1 na Displeji na Breadboarde zapojím do Pinu 9 na Arduine
Pin 9 z cifry č.2 na Displeji na Breadboarde zapojím do Pinu 10 na Arduine
Pin 8 z cifry č.3 na Displeji na Breadboarde zapojím do Pinu 11 na Arduine
Pin 6 z cifry č.4 na Displeji na Breadboarde zapojím do Pinu 12 na Arduine

 */
//Piny na Arduine a premenne pre jednotlive segmenty displeja, znazornene na zaciatku,
int segA = 2; //Pin 11 z displeja na Breadboarde zapojim do Arduina Pinu 2
int segB = 3; //Pin 7 z displeja na Breadboarde je zapojeny do Pinu 3 na Arduine atd...
int segC = 4;
int segD = 5; 
int segE = 6;
int segF = 7; 
int segG = 8; 

int pociatocnyCas=120;  //Pociatocne cislo v sekundach pri ktorom zaciname odpocitavanie 
unsigned long time;  //premenna na cas Arduina
extern volatile unsigned long timer0_millis; //premenna pre resetnutie casu pri stlaceni tlacidla, kvoli tomu ze chceme pocitadlo spustit az po stlaceni tlacidla

void setup() {                
  pinMode(segA, OUTPUT); //segmenty displeja - priradenie outputu
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  pinMode(disp1, OUTPUT); //priradenie outputu k cifram
  pinMode(disp2, OUTPUT);
  pinMode(disp3, OUTPUT);
  pinMode(disp4, OUTPUT);

  //A0 output pre tlacidlo bol priradeny vyssie
  pinMode(A1, OUTPUT); //priradenie Pinu pre ledku
  pinMode(A2, OUTPUT); //priradenie Pinu pre rele

  button.setDebounceTime(50); // debounce tlacidla, aj ked pri 1 stlaceni je nepotrebny
  
}

void loop() {

  button.loop(); // zavolanie loop funkcie pre tlacidlo z ezButton library
  if (button.isPressed()) {
    if (loopState == LOOP_STATE_STOPPED){ //ak je tlacidlo vypnute (pociatocna hodnota)
      loopState = LOOP_STATE_STARTED; // --> tlacidlo zapnut, zamerne tlacidlo pri opatovnom tuknuti nic nespravi (aby si Bond nemohol ten cas predlzit/resetnut)
      timer0_millis = 0; //resetnutie casu Arduina
      digitalWrite(A1,HIGH); //zapnutie LED pre indikovanie spustenia
    }
  }

  if (loopState == LOOP_STATE_STARTED) { //ak tlacidlo stlacime
    if((millis()/1000) < pociatocnyCas){ //pokial je cas menej ako 120 sekund, bude ten loop fungovat
                                     //millis je cas v milisekundach, preto ho vydelime 1000 aby sme dostali sekundy
    zobrazCislo(pociatocnyCas -(millis()/1000)); //zobrazi pociatocne cislo - odpocitavanie
    }
    else {
      digitalWrite(A1,LOW); //zhasne LED
      digitalWrite(A2,HIGH); //spusti Rele
      delay(10000); //na 10 sekund napriklad
    }  
  }
}

void zobrazCislo(int naDispleji) {

#define zapnut_Disp  LOW
#define vypnut_Disp  HIGH

  long internyCas = millis(); //premenna pre interny cas Arduina (v milisekundach)

  for(int disp = 4 ; disp > 0 ; disp--) {

    //zapnutie cifry na kratky cas
    switch(disp) {
    case 1:
      digitalWrite(disp1, zapnut_Disp);
      break;
    case 2:
      digitalWrite(disp2, zapnut_Disp);
      break;
    case 3:
      digitalWrite(disp3, zapnut_Disp);
      break;
    case 4:
      digitalWrite(disp4, zapnut_Disp);
      break;
    }
    
    zasvietCislo(naDispleji % 10);  //zasvieti spravny segment na displeji, ziskame zvysok
    naDispleji = naDispleji / 10;
    zasvietCislo(10); //vypnut vsetky segmenty 

    digitalWrite(disp1, vypnut_Disp);     //vypnut vsetky cifry na displeji
    digitalWrite(disp2, vypnut_Disp);
    digitalWrite(disp3, vypnut_Disp);
    digitalWrite(disp4, vypnut_Disp);
  }

  while( (millis() - internyCas) < 10) ; //pockat nez sa znova zobrazi cas
}

//dostane cas a rozsvieti vsetky segmenty
//cislo 10 sluzi na resetnutie
void zasvietCislo(int cisloKtoreSaZobrazi) {

#define ZAPNUT_Segment HIGH
#define vypnut_Segment LOW

  switch (cisloKtoreSaZobrazi){

  case 0: //cislo 0
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, ZAPNUT_Segment);
    digitalWrite(segE, ZAPNUT_Segment);
    digitalWrite(segF, ZAPNUT_Segment);
    digitalWrite(segG, vypnut_Segment);
    break;

  case 1: //cislo 1
    digitalWrite(segA, vypnut_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, vypnut_Segment);
    digitalWrite(segE, vypnut_Segment);
    digitalWrite(segF, vypnut_Segment);
    digitalWrite(segG, vypnut_Segment);
    break;

  case 2: //cislo 2
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, vypnut_Segment);
    digitalWrite(segD, ZAPNUT_Segment);
    digitalWrite(segE, ZAPNUT_Segment);
    digitalWrite(segF, vypnut_Segment);
    digitalWrite(segG, ZAPNUT_Segment);
    break;

  case 3: //cislo 3
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, ZAPNUT_Segment);
    digitalWrite(segE, vypnut_Segment);
    digitalWrite(segF, vypnut_Segment);
    digitalWrite(segG, ZAPNUT_Segment);
    break;

  case 4: // cislo 4
    digitalWrite(segA, vypnut_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, vypnut_Segment);
    digitalWrite(segE, vypnut_Segment);
    digitalWrite(segF, ZAPNUT_Segment);
    digitalWrite(segG, ZAPNUT_Segment);
    break;

  case 5: //cislo 5
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, vypnut_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, ZAPNUT_Segment);
    digitalWrite(segE, vypnut_Segment);
    digitalWrite(segF, ZAPNUT_Segment);
    digitalWrite(segG, ZAPNUT_Segment);
    break;

  case 6: //cislo 6
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, vypnut_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, ZAPNUT_Segment);
    digitalWrite(segE, ZAPNUT_Segment);
    digitalWrite(segF, ZAPNUT_Segment);
    digitalWrite(segG, ZAPNUT_Segment);
    break;

  case 7: //cislo 7
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, vypnut_Segment);
    digitalWrite(segE, vypnut_Segment);
    digitalWrite(segF, vypnut_Segment);
    digitalWrite(segG, vypnut_Segment);
    break;

  case 8: //cislo 8
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, ZAPNUT_Segment);
    digitalWrite(segE, ZAPNUT_Segment);
    digitalWrite(segF, ZAPNUT_Segment);
    digitalWrite(segG, ZAPNUT_Segment);
    break;

  case 9: //cislo 9
    digitalWrite(segA, ZAPNUT_Segment);
    digitalWrite(segB, ZAPNUT_Segment);
    digitalWrite(segC, ZAPNUT_Segment);
    digitalWrite(segD, ZAPNUT_Segment);
    digitalWrite(segE, vypnut_Segment);
    digitalWrite(segF, ZAPNUT_Segment);
    digitalWrite(segG, ZAPNUT_Segment);
    break;

  case 10: //vypnutie displeja
    digitalWrite(segA, vypnut_Segment);
    digitalWrite(segB, vypnut_Segment);
    digitalWrite(segC, vypnut_Segment);
    digitalWrite(segD, vypnut_Segment);
    digitalWrite(segE, vypnut_Segment);
    digitalWrite(segF, vypnut_Segment);
    digitalWrite(segG, vypnut_Segment);
    break;
  }
}

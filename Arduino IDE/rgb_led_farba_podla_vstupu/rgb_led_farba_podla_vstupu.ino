const int rpin = 9; //cervena led pin
const int bpin = 5; //modra led pin
const int gpin = 6; //zelena led pin
String odpoved;

void setup() {
  Serial.begin(9600);   
  pinMode(rpin,OUTPUT); //definovanie pinov ako output
  pinMode(bpin,OUTPUT);
  pinMode(gpin,OUTPUT);
  Serial.println("Na zmenu farby RGB LED zadaj 3 rozne cisla s medzerou v rozmedzi 0 - 255: ");
  Serial.println("Prve cislo meni cervenu zlozku, druhe zelenu a tretie modru.");
}

void loop() {
  while (Serial.available()) { //funkcia bude prebiehat kym je nieco na vstupe
    int red = Serial.parseInt(); //definovanie premennej pre cervenu farbu, hodnota je zadana uzivatelom
                                  //parseInt potom hlada dalsie platne cislo
    int green = Serial.parseInt(); 
    int blue = Serial.parseInt();
    
    if (Serial.read() == '\n') { //spusti sa ked stlacime enter
      Serial.print("Cervena = "); //vypisanie uzivatelom zadanych premennych
      Serial.print(red);
      Serial.print(" Zelena = ");
      Serial.print(green);
      Serial.print(" Modra = ");
      Serial.print(blue);
      Serial.println();
      //constrain obmedzi rozsah premennej len od 0 do 255, pri vyssom cisle nastavi 255   
      //LED sa pri 255 vypne a pri 0 ma maximalny jas, uzivatelsky je logickejsie ked je to opacne, preto sa to odcita   
      red = 255 - constrain(red, 0, 255);
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);
      analogWrite(rpin, red); //zasvieti jednotlive pixely na led
      analogWrite(gpin, green);
      analogWrite(bpin, blue);
  }
 }
}

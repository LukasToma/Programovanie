const int led = 5; //pin pre ledku
const int buz = 2; //pin pre buzzer
String kod = ""; //zapisovanie stringu
int len = 0; //premenna na zistenie dlzky stringu
char pismeno; //premenna na citanie pismen/charakterov
int pauza = 250; //cas medzi jednotlivymi charaktermi

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);  //ledka
  pinMode(buz, OUTPUT);  //buzzer
  Serial.println("Napis slovo a ja ho prelozim do Morseovky:");
}
void loop() {
  while (Serial.available())
  {
    kod = Serial.readString(); //nacita to co uzivatel napise
    Serial.print(kod); //vypise to co uzivatel napise v klasickej abecede
    Serial.print(" = ");
    stringnamorseovku(); //string rozlozi na jednotlive charaktery
    Serial.println(""); //po vypisani morseovky to prehodi do noveho riadku (pre lepsiu citatelnost)
  }
  delay(1000);
}

void stringnamorseovku() 
{
  len = kod.length(); //zisti dlzku stringu
  for (int i = 0; i < len; i++) //for cyklus aby to precitalo kazde pismeno stringu
  {
    pismeno = kod.charAt(i); //dostane sa k i-temu charakteru stringu
    morseovka(); //spusti citanie pismen
  }
}

void bodka()
{
  Serial.print(".");
  digitalWrite(led, HIGH); //rozsvieti ziarovku
  digitalWrite(buz, HIGH); //zapne buzzer
  delay(pauza);
  digitalWrite(led, LOW); //vypne
  digitalWrite(buz, LOW);
  delay(pauza);
}
void ciarka()
{
  Serial.print("-");
  digitalWrite(led, HIGH);
  digitalWrite(buz, HIGH);
  delay(pauza * 3);
  digitalWrite(led, LOW);
  digitalWrite(buz, LOW);
  delay(pauza);
}

//funkcia na rozoznavanie znakov, ked zisti o ktory znak ide privola funkciu, ktora ho prelozi do morseovej abecedy
void morseovka()
{
if (pismeno == 'A' || pismeno == 'a') //ak detekuje pismeno A alebo a
{
A(); //privola funkciu A, ktora ma v sebe konverziu pismena A do morseovky
Serial.print(" "); //pri vypisovani do Serial Monitoru da medzeru medzi jednotlivymi pismenami
}
else if (pismeno == 'B' || pismeno == 'b')
{
B();
Serial.print(" ");
}
else if (pismeno == 'C' || pismeno == 'c')
{
C();
Serial.print(" ");
}
else if (pismeno == 'D' || pismeno == 'd')
{
D();
Serial.print(" ");
}
else if (pismeno == 'E' || pismeno == 'e')
{
E();
Serial.print(" ");
}
else if (pismeno == 'f' || pismeno == 'f')
{
f();
Serial.print(" ");
}
else if (pismeno == 'G' || pismeno == 'g')
{
G();
Serial.print(" ");
}
else if (pismeno == 'H' || pismeno == 'h')
{
H();
Serial.print(" ");
}
else if (pismeno == 'I' || pismeno == 'i')
{
I();
Serial.print(" ");
}
else if (pismeno == 'J' || pismeno == 'j')
{
J();
Serial.print(" ");
}
else if (pismeno == 'K' || pismeno == 'k')
{
K();
Serial.print(" ");
}
else if (pismeno == 'L' || pismeno == 'l')
{
L();
Serial.print(" ");
}
else if (pismeno == 'M' || pismeno == 'm')
{
M();
Serial.print(" ");
}
else if (pismeno == 'N' || pismeno == 'n')
{
N();
Serial.print(" ");
}
else if (pismeno == 'O' || pismeno == 'o')
{
O();
Serial.print(" ");
}
else if (pismeno == 'P' || pismeno == 'p')
{
P();
Serial.print(" ");
}
else if (pismeno == 'Q' || pismeno == 'q')
{
Q();
Serial.print(" ");
}
else if (pismeno == 'R' || pismeno == 'r')
{
R();
Serial.print(" ");
}
else if (pismeno == 'S' || pismeno == 's')
{
S();
Serial.print(" ");
}
else if (pismeno == 'T' || pismeno == 't')
{
T();
Serial.print(" ");
}
else if (pismeno == 'U' || pismeno == 'u')
{
U();
Serial.print(" ");
}
else if (pismeno == 'V' || pismeno == 'v')
{
V();
Serial.print(" ");
}
else if (pismeno == 'W' || pismeno == 'w')
{
W();
Serial.print(" ");
}
else if (pismeno == 'X' || pismeno == 'x')
{
X();
Serial.print(" ");
}
else if (pismeno == 'Y' || pismeno == 'y')
{
Y();
Serial.print(" ");
}
else if (pismeno == 'Z' || pismeno == 'z')
{
Z();
Serial.print(" ");
}
else if (pismeno == '0')
{
nula();
Serial.print(" ");
}
else if (pismeno == '1')
{
jedna();
Serial.print(" ");
}
else if (pismeno == '2')
{
dva();
Serial.print(" ");
}
else if (pismeno == '3')
{
tri();
Serial.print(" ");
}
else if (pismeno == '4')
{
styri();
Serial.print(" ");
}
else if (pismeno == '5')
{
pat();
Serial.print(" ");
}
else if (pismeno == '6')
{
sest();
Serial.print(" ");
}
else if (pismeno == '7')
{
sedem();
Serial.print(" ");
}
else if (pismeno == '8')
{
osem();
Serial.print(" ");
}
else if (pismeno == '9')
{
devat();
Serial.print(" ");
}
else if(pismeno == ' ') //ak to zisti medzeru, teda nove slovo, tak da tomu adekvatnu pauzu a ciaru na predelenie 
{
Serial.print(" | ");
delay(pauza*7);
}
}

//Vytvorenie funkcii, ktore pisu uz detekovane pismena a cisla v Morseovej abecede
void A()
{
bodka();
delay(pauza);
ciarka();
delay(pauza);
}
void B()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void C()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
}
void D()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void E()
{
bodka();
delay(pauza);
}
void f()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
}
void G()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
}
void H()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void I()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void J()
{
bodka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void K()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
}
void L()
{
bodka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void M()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void N()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
}
void O()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void P()
{
bodka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
}
void Q()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
}
void R()
{
bodka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
}
void S()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void T()
{
ciarka();
delay(pauza);
}
void U()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
}
void V()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
}
void W()
{
bodka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void X()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
}
void Y()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void Z()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void jedna()
{
bodka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void dva()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void tri()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}
void styri()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
ciarka();
delay(pauza);
}
void pat()
{
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void sest()
{
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void sedem()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void osem()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
bodka();
delay(pauza);
}
void devat()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
bodka();
delay(pauza);
}
void nula()
{
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
ciarka();
delay(pauza);
}

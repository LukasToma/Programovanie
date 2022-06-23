const int echo = 2;
const int trig = 3;

long cas; // premenna na cas putovania ultrazvuku
int vzdialenost; // premenna na vzdialenost

void setup() {
  pinMode(trig, OUTPUT); // nastavenie trig a echo pinov
  pinMode(echo, INPUT); 
  Serial.begin(9600);
  Serial.println("Ultrazvukovy senzor HC-SR04 s rozsahom od 2 do 400 cm.");
}
void loop() {
  // vypne trig pin
  digitalWrite(trig, LOW);
  delay(200); //spomalenie vypisovania dat kvoli lepsej citatelnosti 
  // zapne trig na 10 mikrosekund
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW); // precita to echo a da nam to cas putovania ultrazvuku v mikrosekundach
  cas = pulseIn(echo, HIGH);
  vzdialenost = cas * 0.034 / 2; //rychlost zvuku vydelena 2 (lebo ultrazvuk cestuje tam a spat)

  if (vzdialenost<400) { //senzor ma rozsah 2 az 400 cm na zaklade data sheetu, pri hodnotach mimo rozsahu zvycajne vrati hodnotu cca 2139
    Serial.print("Vzdialenost od senzoru je "); //vypise vzdialenost v cm ak je v rozsahu senzoru
    Serial.print(vzdialenost);
    Serial.println(" cm");
  } 
  else {
    Serial.println("Senzor je moc blizko alebo daleko. Rozsah senzoru je od 2 do 400 cm."); //vypise chybovu hlasku ak je hodnota mimo rozsahu senzoru
  }

        
}

#define inu A0 //wejscie analogowe 0 to wczytywane napiecie
int uint;
float ureal;

void setup()
{
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(inu, INPUT);
}

void loop()
{
  uint = analogRead(inu);
  ureal = uint * (5.0 / 1023.0); // Konwersja wartości analogowej na napięcie (zakładając maksymalne napięcie 5V)

  Serial.print("Wartość wczytana w int: ");
  Serial.println(uint);
  
  Serial.print("Napięcie: ");
  Serial.print(ureal);
  Serial.println(" V");
  
  delay(500);
}
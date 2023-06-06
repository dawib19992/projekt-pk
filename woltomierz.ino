#define inu A0      //wejście analogowe 0 to wczytywane napięcie

int uint;
float ureal;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(inu, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  uint = analogRead(inu);
  Serial.print("Wartość wczytana jako int: ");
  Serial.println(uint);
  
  ureal = uint * (5.0 / 1023.0);  // Przeliczenie wartości odczytanej na napięcie
  Serial.print("Wartość wczytana jako napięcie: ");
  Serial.print(ureal, 2);  // Wyświetlenie wartości z dwoma miejscami po przecinku
  Serial.println(" V");
  
  delay(500);
}

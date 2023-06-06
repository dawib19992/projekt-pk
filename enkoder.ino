#define iclk 2 // wejście 2 to przebieg A (zegar / impulsator)
#define idir 3 // wejście 3 to przebieg B (sygnał kierunku obrotu)
#define ireset 4 // wejście 4 po przyciśnięciu to 0 dla np. resetowania kąta

const float st_na_imp = 360.0 / 40.0; // każdy impuls enkodera odpowiada 9 stopniom

bool oldclk, clk, dir, reset;
unsigned long czas;
int obroty = 0; // licznik pełnych obrotów enkodera

void setup()
{
  Serial.begin(9600);
  pinMode(iclk, INPUT);
  pinMode(idir, INPUT);
  pinMode(ireset, INPUT);
  oldclk = digitalRead(iclk);
}

void loop()
{
  clk = digitalRead(iclk);
  dir = digitalRead(idir);
  reset = digitalRead(ireset);

  if (clk != oldclk)
  {
    if (dir == LOW)
    {
      obroty++;
    }
    else
    {
      obroty--;
    }

    Serial.print("Liczba obrotów: ");
    Serial.println(obroty);

    oldclk = clk;
  }

  if (reset == LOW)
  {
    obroty = 0;
    Serial.println("Zresetowano liczbę obrotów.");
    delay(500); // opóźnienie w celu uniknięcia wielokrotnego zresetowania podczas jednego wciśnięcia przycisku
  }
}
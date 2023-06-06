#include <Servo.h>

Servo servohori;
int servoh = 110;
int servohLimitHigh = 160;
int servohLimitLow = 60;

Servo servoverti;
int servov = 110;
int servovLimitHigh = 160;
int servovLimitLow = 60;

// Zdefiniowanie zmiennych oznaczających numery wyprowadzeń,
// do których są dołączone fotorezystory
int ldrtopl = 1; // Top Left
int ldrtopr = 2; // Top Right
int ldrbotl = 4; // Bottom Left
int ldrbotr = 3; // Bottom Right

void setup()
{
  servohori.write(110);      // Ustalenie początkowej pozycji serwomechanizmu pracującego w poziomie
  servoverti.write(110);     // Ustalenie początkowej pozycji serwomechanizmu pracującego w pionie
  servohori.attach(11);      // Przypisanie do wyprowadzenia 11 układu Arduino sygnału sterującego serwomechanizmem działającym w poziomie
  servoverti.attach(10);     // Przypisanie do wyprowadzenia 10 układu Arduino sygnału sterującego serwomechanizmem działającym w pionie
  Serial.begin(9600);        // Ustawienie parametrów działania portu szeregowego układu Arduino
  delay(500);
  // Opóźnienie przed rozpoczęciem działania cyklicznej części programu
}

void loop()
{
  int ldrTopLeft = analogRead(ldrtopl);
  int ldrTopRight = analogRead(ldrtopr);
  int ldrBottomLeft = analogRead(ldrbotl);
  int ldrBottomRight = analogRead(ldrbotr);

  // Obliczanie średniej wartości sygnałów fotorezystorów górnego rzędu
  int ldrTopAverage = (ldrTopLeft + ldrTopRight) / 2;

  // Obliczanie średniej wartości sygnałów fotorezystorów dolnego rzędu
  int ldrBottomAverage = (ldrBottomLeft + ldrBottomRight) / 2;

  // Obliczanie różnicy między sygnałami fotorezystorów lewej i prawej kolumny
  int ldrDifference = ldrTopLeft - ldrTopRight;

  // Sterowanie osią elewacji (pion)
  if (ldrTopAverage < ldrBottomAverage)
  {
    if (servov > servovLimitLow)
    {
      servov--;
    }
  }
  else if (ldrTopAverage > ldrBottomAverage)
  {
    if (servov < servovLimitHigh)
    {
      servov++;
    }
  }

  // Sterowanie osią azymutu (poziom)
  if (ldrDifference > 10)
  {
    if (servoh > servohLimitLow)
    {
      servoh--;
    }
  }
  else if (ldrDifference < -10)
  {
    if (servoh < servohLimitHigh)
    {
      servoh++;
    }
  }

  // Aktualizacja pozycji serwomechanizmów
  servohori.write(servoh);
  servoverti.write(servov);

  delay(50);
}
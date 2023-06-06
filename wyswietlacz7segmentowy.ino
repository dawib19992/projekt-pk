//cyfra lewa Digit Left
#define DLa 2 //segment a wyjscie 2
#define DLb 3 //segment b wyjscie 3
#define DLc 4 //segment c wyjscie 4
#define DLd 5 //segment d wyjscie 5
#define DLe 6 //segment e wyjscie 6
#define DLf 7 //segment f wyjscie 7
#define DLg 8 //segment g wyjscie 8
#define DLdp 9 //kropka wyjscie 9
#define DLkat 10 //katoda wyjscie 10

//cyfra prawa Digit Right
#define DRa 11 //segment a wyjscie 11
#define DRb 12 //segment b wyjscie 12
#define DRc 13 //segment c wyjscie 13
#define DRd A0 //segment d wyjscie A0
#define DRe A1 //segment e wyjscie A1
#define DRf A2 //segment f wyjscie A2
#define DRg A3 //segment g wyjscie A3
#define DRdp A4 //kropka wyjscie A4
#define DRkat A5 //katoda wyjscie A5

struct port_nazwa
{
  String opis;
  int port;
};

port_nazwa tab_port_DL[9], tab_port_DR[9];

void wylacz(port_nazwa tab_port[])
{
  digitalWrite(tab_port[8].port, 0); // wylączenie katody
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(tab_port[i].port, 0);
  }
}

void wlacz(port_nazwa tab_port[])
{
  digitalWrite(tab_port[8].port, 1); // wlączenie katody
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(tab_port[i].port, 1);
  }
}

void AL()
{
  wylacz(tab_port_DL);
  digitalWrite(DLkat, 1);
  digitalWrite(DLa, 1);
  /*
   * Tutaj włącz pozostałe segmenty
   */
  delay(500);
  wylacz(tab_port_DL);
}

void setup()
{
  Serial.begin(9600);
  pinMode(DLa, OUTPUT);
  pinMode(DLb, OUTPUT);
  pinMode(DLc, OUTPUT);
  pinMode(DLd, OUTPUT);
  pinMode(DLe, OUTPUT);
  pinMode(DLf, OUTPUT);
  pinMode(DLg, OUTPUT);
  pinMode(DLdp, OUTPUT);
  pinMode(DLkat, OUTPUT);

  pinMode(DRa, OUTPUT);
  pinMode(DRb, OUTPUT);
  pinMode(DRc, OUTPUT);
  pinMode(DRd, OUTPUT);
  pinMode(DRe, OUTPUT);
  pinMode(DRf, OUTPUT);
  pinMode(DRg, OUTPUT);
  pinMode(DRdp, OUTPUT);
  pinMode(DRkat, OUTPUT);
}

void loop()
{
  // Tutaj umieść swój kod główny, aby działał w pętli
}
//lewa cyfra Digit Left
#define DLa 2
#define DLb 3
#define DLc 4
#define DLd 5
#define DLe 6
#define DLf 7
#define DLg 8
#define DLdp 9
#define DLkat 10

//prawa cyfra Digit Right
#define DRa 11
#define DRb 12
#define DRc 13
#define DRd A0
#define DRe A1
#define DRf A2
#define DRg A3
#define DRdp A4
#define DRkat A5

struct port_nazwa
{
  String opis;
  int port;
};

port_nazwa tab_port_DL[9], tab_port_DR[9];

void init_tab_port_DL()
{
  port_nazwa pin;

  for (int i = 2; i <= 8; i++)
  {
    pin.opis = "DL" + (String)(char(95 + i));
    pin.port = i;
    tab_port_DL[i - 2] = pin;
  }
  pin.opis = "DLdp";
  pin.port = 9;
  tab_port_DL[7] = pin;

  pin.opis = "DLkat";
  pin.port = 10;
  tab_port_DL[8] = pin;
}

void wypisz_tab_port(port_nazwa tab_port[9])
{
  Serial.println("Nowa tablica");
  Serial.println("");

  for (int i = 0; i < 9; i++)
  {
    Serial.print("Element :");
    Serial.println(i);
    Serial.println(tab_port[i].opis);
    Serial.println(tab_port[i].port);
  }
}

void init_tab_port_DR()
{
  port_nazwa pin;
  for (int i = 11; i <= 19; i++)
  {
    pin.opis = "DR" + (String)(char(i));
    pin.port = i;
    tab_port_DR[i - 11] = pin;
  }
}

void DLtest_kropki()
{
  //wlaczenie katody lewej cyfry
  digitalWrite(DLkat, HIGH);

  digitalWrite(DLdp, HIGH);

  delay(1000);
  digitalWrite(DLkat, LOW);

  //wylaczenie katody lewej cyfry
  digitalWrite(DLdp, LOW);

  delay(1000);
}

void test_segmentow(port_nazwa tab_port[9])
{
  //wlaczenie katody
  digitalWrite(tab_port[8].port, HIGH);

  for (int licznik = 0; licznik < 8; licznik++)
  {
    digitalWrite(tab_port[licznik].port, HIGH);
    delay(500);
    digitalWrite(tab_port[licznik].port, LOW);
    delay(500);
  }
  digitalWrite(tab_port[8].port, LOW);
}

void wlacz(port_nazwa tab_port[9])
{
  //wlaczenie katody
  digitalWrite(tab_port[8].port, HIGH);
  for (int i = 0; i < 8; i++)
    digitalWrite(tab_port[i].port, HIGH);
}

void wylacz(port_nazwa tab_port[9])
{
  //wylaczenie katody i to w zasadzie wystarczy, ale
  digitalWrite(tab_port[8].port, LOW);
  for (int i = 0; i < 8; i++)
    digitalWrite(tab_port[i].port, LOW);
}

void czytaj_konsole()
{
  String wczytany_string = "";
  char tab[10];
  char znak;
  int licznik = 0;

  //...

  if (Serial.available() > 0) //czy są dane do wczytania?
  {

    Serial.println("wczytano " + wczytany_string);
    //...
    znak = wczytany_string.charAt(0);
    //...
    wczytany_string.remove(0, 1);
    //...
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("wystartowal");

  //konfiguracja portów
  //DL
  pinMode(DLa, OUTPUT);
  digitalWrite(DLa, LOW);
  pinMode(DLb, OUTPUT);
  digitalWrite(DLb, LOW);
  pinMode(DLc, OUTPUT);
  digitalWrite(DLc, LOW);
  pinMode(DLd, OUTPUT);
  digitalWrite(DLd, LOW);
  pinMode(DLe, OUTPUT);
  digitalWrite(DLe, LOW);
  pinMode(DLf, OUTPUT);
  digitalWrite(DLf, LOW);
  pinMode(DLg, OUTPUT);
  digitalWrite(DLg, LOW);
  pinMode(DLdp, OUTPUT);
  digitalWrite(DLdp, LOW);
  pinMode(DLkat, OUTPUT);
  digitalWrite(DLkat, LOW);

  //DR
  pinMode(DRa, OUTPUT);
  digitalWrite(DRa, LOW);
  pinMode(DRb, OUTPUT);
  digitalWrite(DRb, LOW);
  pinMode(DRc, OUTPUT);
  digitalWrite(DRc, LOW);
  pinMode(DRd, OUTPUT);
  digitalWrite(DRd, LOW);
  pinMode(DRe, OUTPUT);
  digitalWrite(DRe, LOW);
  pinMode(DRf, OUTPUT);
  digitalWrite(DRf, LOW);
  pinMode(DRg, OUTPUT);
  digitalWrite(DRg, LOW);
  pinMode(DRdp, OUTPUT);
  digitalWrite(DRdp, LOW);
  pinMode(DRkat, OUTPUT);
  digitalWrite(DRkat, LOW);

  init_tab_port_DL();
  wypisz_tab_port(tab_port_DL);

  init_tab_port_DR();
  wypisz_tab_port(tab_port_DR);
}

void loop()
{
  // put your main code here, to run repeatedly:

  DLtest_kropki();

  test_segmentow(tab_port_DL);

  wlacz(tab_port_DL);

  wylacz(tab_port_DL);

  //czytaj_konsole();
}

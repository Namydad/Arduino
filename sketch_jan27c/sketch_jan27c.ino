#define _DATUM "2023 01 27"
#define _AUTOR "Fech"
#define _A_PIN 0  // für Auswahl
#define _F_PIN 2  // für Frequenz
#define _H_PIN 4  // für Helligkeit

// Prototypen
int pwm_blinkautomat();
int A_gedrueckt();
int F_gedrueckt();
int H_gedrueckt();

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.printf("Name: %s, Datum: %s\n", _AUTOR, _DATUM);

  pinMode(_A_PIN, INPUT_PULLUP);
  pinMode(_F_PIN, INPUT_PULLUP);
  pinMode(_H_PIN, INPUT_PULLUP);
}

void loop()
{
  int tmp = pwm_blinkautomat();
  Serial.printf("Der Automat befindet sich im Zustand: %i\n", tmp);
}

int A_gedrueckt()
{
  return !digitalRead(_A_PIN); // lese A ein
}
int F_gedrueckt()
{
  return !digitalRead(_F_PIN); // lese F ein
}
int H_gedrueckt()
{
  return !digitalRead(_H_PIN); // lese H ein
}

enum pwm_blinkautomat_t
{
  WarteVorBlinken, Blinken,
  WarteVorRot, RotGewaehlt,
  WarteVorGruen, GruenGewaehlt, 
  FrequenzAendern, HelligkeitAendern
};

int pwm_blinkautomat()
{
  static pwm_blinkautomat_t zustand = Blinken; // Merke Zustand
  int A = A_gedrueckt();  // LED-Auswahl (blinken -> rot -> grün -> blinken -> ...)
  int F = F_gedrueckt();  // Frequenz ändern
  int H = H_gedrueckt();  // Helligkeit ändern
  static int RT = 0;  // Merke, dass rot gewählt
  static int GN = 0;  // Merke, dass grün gewählt

  switch(zustand)
  {
    case WarteVorBlinken:
      //if (A == 0)
      if(!A)
        zustand = Blinken;
      break;
    case Blinken:
      //if (A == 1)
      if(A)
        zustand = WarteVorRot;
      break;
    case WarteVorRot:
      if (A == 0)
        zustand = RotGewaehlt;
      break;
    case RotGewaehlt:
      RT = 1;
      GN = 0;
      
      if (A == 1)
        zustand = WarteVorGruen;
      else if (F == 1)
        zustand = FrequenzAendern;
      else if (H == 1)
        zustand = HelligkeitAendern;
      break;
    case WarteVorGruen:
      if (A == 0)
        zustand = GruenGewaehlt;
      break;
    case GruenGewaehlt:
      RT = 0;
      GN = 1;
      
      if (A == 1)
        zustand = WarteVorBlinken;
      else if (F == 1)
        zustand = FrequenzAendern;
      else if (H == 1)
        zustand = HelligkeitAendern;
      break;
    case FrequenzAendern:
      if (F == 0 && RT == 1)
        zustand = RotGewaehlt;
      else if (F == 0 && GN == 1)
        zustand = GruenGewaehlt;      
      break;
    case HelligkeitAendern:
      if (H == 0 && RT == 1)
        zustand = RotGewaehlt;
      else if (H == 0 && GN == 1)
        zustand = GruenGewaehlt;       
      break;
  }
  
  return (int)zustand;
}
// DEFINES
#define _DATUM "2023 01 13"
#define _AUTOR "Namydad"
#define _PWM_FREQUENZ 100  // soll eine Periodendauer von 1ms haben
#define _PWM_BITS     10  // soll min 1000 und nicht mehr als 2000 Abstufungen haben
#define _LEDGRN_PIN   33  // siehe Board
#define _LEDGRN_KANAL 0  // frei wählbar
#define _LEDROT_PIN   32  // siehe Board
#define _LEDROT_KANAL 1  // frei wählbar

// GLOBALE VARIABLEN
int max_pwm_wert = 0; // wird in Setup berechnet

// PROTOTYPEN ( = Funktionsköpfe mit Semikolon am Ende)



void setup()
{
  // Serial-Init
  Serial.begin(115200);
  delay(1000);
  Serial.printf("Datum: %s, Autor: %s\n", _DATUM, _AUTOR);

  //PWM-Init
  ledcSetup(_LEDGRN_KANAL, _PWM_FREQUENZ, _PWM_BITS);
  ledcAttachPin(_LEDGRN_PIN, _LEDGRN_KANAL);
  ledcSetup(_LEDROT_KANAL, _PWM_FREQUENZ, _PWM_BITS);
  ledcAttachPin(_LEDROT_PIN, _LEDROT_KANAL);
  
  max_pwm_wert = 1234; // Zahl muss abhängig von den Bits berechnet werden.
}

void loop()
{
  int a0_wert;
  int pwm_wert_grn, pwm_wert_rot;

  a0_wert   = analogRead(A0);       //    0 bis 4095
  pwm_wert_grn = getPWM_grn(a0_wert);     //    PWM-Wert für grün wird berechnet
  pwm_wert_rot = getPWM_rot(a0_wert);     //    - für rot

  setPWM(_LEDGRN_KANAL, pwm_wert_grn);
  setPWM(_LEDROT_KANAL, pwm_wert_rot);
  
  Serial.printf("A0: %4i - max. PWM-Wert: %4i - Grün: %4i - Rot: %4i\n", a0_wert, max_pwm_wert, pwm_wert_grn, pwm_wert_rot);
}

int getPWM_grn(int poti)
{
  int erg = 0;
  
  // WENN poti zwischen 0 und 2048, DANN mapping
  erg = map(poti, 0, 2048, 0, max_pwm_wert); // min/max abhängig davon, ob low-active oder high-active --> muss evtl geändert werden
  //if (poti > 2047){
  //  erg = 0;
  //}
  
  return erg;
}

int getPWM_rot(int poti)
{
  int erg = 0;
  
  // WENN poti zwischen 2048 und 4095, DANN mapping
  erg = map(poti, 2048, 4095, max_pwm_wert, 0); // min/max abhängig davon, ob low-active oder high-active --> muss evtl geändert werden
  if (poti == 2048 ){
    erg = max_pwm_wert;
  }
  
  return erg;
}

void setPWM(int kanal, int wert)
{
  ledcWrite(kanal, wert);
}

/*
 * Aufgabe: Zusätzlich zum Digitalwert und der Prozentangabe,
 * soll zusätzlich die Spannung mit zwei Nachkommastellen 
 * ausgegeben werden. 
 * Beispiele:
 * Digitalwert = 4095 - Prozent: 100,0% - Spannung: 3,30V
 * Digitalwert =    0 - Prozent:   0,0% - Spannung: 0,00V
 */
void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.printf("2022 10 10 - Fech - Musterlösung");
}

void loop()
{
  //loesung_mit_punkt();
  //loesung_mit_komma();

  printPoti();

  int digi = getPotiDigi();
  float prozent = getPotiProzent();
}

float getPotiProzent()
{
  float prozent  = mapFloat(getPotiDigi(), 0, 4095, 0, 100);
  return prozent;
}

int getPotiDigi()
{
  return analogRead(A0);
}

void printPoti()
{
  int digi    = analogRead(A0);
  float volt  = mapFloat(digi, 0, 4095, 0, 3.3);
  Serial.printf("Digi: %4i - Volt: %3.2f\n", digi, volt);
}

float mapFloat(int x, int xMin, int xMax, float yMin, float yMax)
{
  float erg = (float)map(x, xMin, xMax, (yMin*1000.0), (yMax*1000.0)) / 1000.0;
  return erg;
}

void loesung_mit_komma()
{
  int   digi;
  float prozent;
  int   prozent_vorkomma, prozent_nachkomma;
  float volt;
  int   volt_vorkomma, volt_nachkomma;

  digi    = analogRead(A0);
  prozent = (float)map(digi, 0, 4095, 0, 100*10) / 10.0;  // z.B. 50.29
  prozent_vorkomma  = (int)prozent;                       // 50
  prozent_nachkomma = (int)((prozent - (float)prozent_vorkomma) * 10.0);
                            // 50.29 - 50.0 -> 0.29 -> 0.29 * 10.0 -> 2.9 -> 2
  
  volt    = (float)map(digi, 0, 4095, 0, 330) / 100.0;
  volt_vorkomma  = (int)volt;
  volt_nachkomma = (int)((volt - (float)volt_vorkomma) * 100.0);   
  
  
  Serial.printf("Digitalwert = %4i - Prozent: %i,%i%% - Spannung: %i,%iV\n", 
           digi, prozent_vorkomma, prozent_nachkomma, volt_vorkomma, volt_nachkomma);
                                  // 0.29 -> 2.9 -> 2
  Serial.printf("Digitalwert = %4i - Prozent: %i,%.0f%% - Spannung: %i,%iV\n", 
           digi, prozent_vorkomma, (prozent-prozent_vorkomma)*10, volt_vorkomma, volt_nachkomma);
                                  // 50.29-50.00 -> 0.29 -> 0.29 -> 2.9 -> 3

  char buf[50];
  sprintf(buf, "Digitalwert = %4i - Prozent: %5.1f%% - Spannung: %4.2fV\n", digi, prozent, volt);
  String meinString = String(buf);
  meinString.replace(".", ",");
  Serial.printf("%s", meinString.c_str());
}

/*void loesung_mit_punkt()
{
  int digi;
  float prozent;
  float volt;

  digi    = analogRead(A0);
  prozent = (float)map(digi, 0, 4095, 0, 100*10) / 10.0;
  volt    = (float)map(digi, 0, 4095, 0, 330) / 100.0;
  
  Serial.printf("Digitalwert = %4i - Prozent: %5.1f%% - Spannung: %4.2fV\n", digi, prozent, volt);
}
*/

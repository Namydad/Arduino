#define _NAME "Namydad"
#define _DATUM "27-09-2022"
void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.printf("Name: %s Datum: &s\n", _NAME, _DATUM);
}

void loop() {
  int digi;
  digi = analogRead(A0);

  int newnumber = map(digi,0,4095,-12,259);

  Serial.printf("digi %2i - Temperatur: %4i°C\n",digi, newnumber);
  delay(250);
}

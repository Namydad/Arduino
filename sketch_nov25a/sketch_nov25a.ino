#define _AUTHOR "Tobias Lammer"
#define _DATE "25-NOV-2022"


void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.printf("The Programm was written by %s , on the Date: %s \n",_AUTHOR,_DATE);
  
}

void loop() {
  int digi_a0 = analogRead(A0);
  #int digi_touch0 = touchRead(T0);
  #int digi2Voltage = map(digi_a0, 0, 4095,0,33000);
  #float digi2Volt = digi2voltage/10000.0WW
  volt = digi2Volt(digi_a0)
  Serial.printf("Digi: %i, Volt: %.2f \n", digi_a0,digi2Volt);
}
void digi2Volt(digi_a0))  {
  int digi2Voltage = map(digi_a0, 0, 4095,0,33000);
  float digi2Volt = digi2voltage/10000.0
  return digi2Volt
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ledcSetup(0,10,12);
  pinMode(31,OUTPUT);
  ledcAttachPin(31,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int poti = analogRead(A0);
  int winkel = map(poti,0,4095,-9000,9000);
  int ti = map(winkel,-9000,9000,1000,2000);
  int pwm_wert = map(ti,0,20000,0,4095);
  
  ledcWrite(1,pwm_wert);
  
  Serial.printf("%4i - Winkel, %4i - Poti, %4i - ti, %4i - pwm_wert \n",winkel,poti,ti,pwm_wert);
}

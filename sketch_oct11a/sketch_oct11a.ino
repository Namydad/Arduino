void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ledcSetup(0,10,11);
  pinMode(32,OUTPUT);
  ledcAttachPin(32,0);
  pinMode(33,OUTPUT);
  ledcAttachPin(33,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  
int digi = analogRead(A0);  
int wert = map(digi,0,4095,0,2047);
int green = map(digi,0,4095,2047,0);

ledcWrite(0,wert);
ledcWrite(1,green);
Serial.printf("%4i, %4i\n",digi,wert);
Serial.printf("%4i, %4i\n",digi,green );
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.printf("Touch Sensor");
  delay(1000);
  ledcSetup(0,150,10);
  ledcSetup(1,150,10);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  ledcAttachPin(32,0);
  ledcAttachPin(33,1);
}
void loop() {
  int touchwert = touchRead(T3);
  int touch_map = map(touchwert,1,66,0,1023);
  touch_map = constrain(touch_map,0,1023);
  int touch_map1 = map(touchwert,1,66,1023,0);
  touch_map1 = constrain(touch_map1,1023,0);
  

  int touch_prozent = map(touchwert,3,66,0,100000);
  touch_prozent = constrain(touch_prozent,0,100000);


  float touch_prozentt = float(touch_prozent) / 1000.0;
  ledcWrite(0,touch_map);
  ledcWrite(1,touch_map1);
  Serial.printf("Touchwert: %i, in Prozent: %6.2f%% map1 = %i map2 = %i \n", touchwert, touch_prozentt, touch_map, touch_map1);


}

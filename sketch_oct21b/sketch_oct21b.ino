void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touched = touchRead(T3);
  int touching = map(touched,0,65,0,10000);

  prozent = constrain(prozent,0,10000);
  //if(touched < 70){
  //  touching = 0;
  //}
  //else if(touching > 5){
  //  touching = 0;
  //}
  
  Serial.printf("Press: %i, Touch%3i \n",touched, touching);
}

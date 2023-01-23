void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  delay(5000);
  Serial.printf("This is the calculation test");
}

void loop() {
  // 
  float m = -48.6;
  float y = 700;
  float b = 4386;
  float x = x;
  float calc = (700-4386)/(-48,6);
  // print out the values you read:
  Serial.printf("The Values of the Function are m = %f, y=%f, b=%f, x=f%\n",m,y,b,x);
  Serial.printf("The Calculation equals x = %f\n",calc);
  
  delay(100);  // delay in between reads for clear read from serial
}

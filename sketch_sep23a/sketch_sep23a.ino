#define _DATUM "2022-09-23"
#define _NAME "Tobias"

//double soft_version = 0.01;
float soft_version = 1.59

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //normal: 9600, 19200, 115200

  //Serial.printf ("Hallo");
  delay(1000);
  Serial.printf("Datum: %s Name: %s Version: %5.3f\n", _DATUM, _NAME, soft_version);
}

void loop() { 
  // put your main code here, to run repeatedly:

}

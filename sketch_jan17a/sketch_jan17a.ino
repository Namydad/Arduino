// DEFINES
#define _DATUM "2023 01 13"
#define _AUTOR "Namydad"
#define _PWM_FREQUENZ 100  // soll eine Periodendauer von 1ms haben
#define _PWM_BITS     10  // soll min 1000 und nicht mehr als 2000 Abstufungen haben
#define _LED_PIN   33  // siehe Board
#define _LED_KANAL 0  // frei wählbar
void setup() {
  // Serial-Init
  Serial.begin(115200);
  delay(1000);
  Serial.printf("Datum: %s, Autor: %s\n", _DATUM, _AUTOR);
  pinMode(_LED_PIN,OUTPUT);
 
}
void loop(){
  automat1();
}

void automat1() {
  // put your main code here, to run repeatedly:
  static int zustand = 1;
  static unsigned long gz = millis();

  switch(zustand){
    case 1: led_grn(1);
            gz = millis();
            if(millis() >= gz + 100){
              gz = millis();
              zustand = 2;
            }
            break;
            
  }
}
void led_grn(int on){
  if (on)
    digitalWrite(_LED_PIN,HIGH);
  else
    digitalWrite(_LED_PIN,LOW);
}

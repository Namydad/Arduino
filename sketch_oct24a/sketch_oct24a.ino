#define _DATUM "2022-10-21"
#define _AUTOR "2BKI21"
#define _TOUCH_PIN T3
#define _TOUCH_PIN_MIN 59
#define _TOUCH_PIN_MAX 36
#define _PWM_PIN 32

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.printf("Datum : %s, Autor : %s \n",_DATUM,_AUTOR);
  pinMode(_PWM_PIN,OUTPUT);
  ledcAttachPin(_PWM_PIN,0);
  ledcSetup(0, 240, 10);
}

void loop()
{
  int touch_value = touchRead(_TOUCH_PIN);
  
  int prozent = map(touch_value,_TOUCH_MIN,_TOUCH_MAX,100000,0);
  prozent = constrain(prozent,0,100000); //   if (prozent < 0 ) prozent = 0;  else if (prozent > 100000) prozent = 100000;

  int pwm_wert = map(prozent,0,100000,0,1023);

  ledcWrite(0, pwm_wert);
  Serial.printf("Touch Wert; %i, Prozent: %i, PWM: %i\n",touch_value,prozent, pwm_wert);
}

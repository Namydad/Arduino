#define LED_PIN 33
#define LED_PIN2 32

void setup() {
   pinMode(LED_PIN, OUTPUT);
   pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  automat1();
  automat2();

}

void ledgrn(int on)
{
  if(on)
    digitalWrite(LED_PIN, HIGH);
   else
    digitalWrite(LED_PIN, LOW);

  }
void ledred(int on)
{
  if(on)
    digitalWrite(LED_PIN2, LOW);
   else
    digitalWrite(LED_PIN2, HIGH);

  }
void automat1()
{
  static int zustand = 1;
  static unsigned long gz = millis();
  switch (zustand)
  {
    case 1: ledgrn(1);
      if(millis() >= gz + 100)
      {
        gz = millis ();
        zustand = 2;
        }
        break;
    case 2: ledgrn(0);
      if(millis() >= gz + 100)
      {
        zustand = 3;
        gz = millis();
        }
        break;
     case 3: ledgrn(1);
      if(millis() >= gz + 100)
      {
        zustand = 4;
        gz = millis();
        } 
        break;
     case 4: ledgrn(0);
       if(millis() >= gz + 1700)
       {
        zustand = 1;
        gz = millis();
       }
       break;
    }
}
void automat2()
{
  static int zustand2 = 1;
  static unsigned long gz2 = millis();
  switch (zustand2)
  {
    case 1: ledred(1);
      if(millis() >= gz2 + 100)
      {
        gz2 = millis ();
        zustand2 = 2;
        }
        break;
    case 2: ledred(0);
      if(millis() >= gz2 + 100)
      {
        zustand2 = 3;
        gz2 = millis();
        }
        break;
     case 3: ledred(1);
      if(millis() >= gz2 + 100)
      {
        zustand2 = 4;
        gz2 = millis();
        } 
        break;
     case 4: ledred(0);
       if(millis() >= gz2 + 1700)
       {
        zustand2 = 1;
        gz2 = millis();
       }
       break;
    }
 }
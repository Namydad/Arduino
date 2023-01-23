#define _X1 6
#define _X2 15
#define _X3 30
#define _X4 70
#define _Y1 3908
#define _Y2 2047
#define _Y3 1116
#define _Y4 496


void loop()
  {
  int meinDigi = analogRead(A0);
  float dist = getDistance(meinDigi);
    if(dist >= 0)
      Serial.printf("Abstand zur Wand: %4.1fcm\n", dist);
    else
      Serial.printf("Kann die Wand nicht sehen\n", dist);
  }
  float getDistance(int aktuellerDigitalwert)
    {
    if(aktuellerDigitalwert > _Y1)
        return 0;
      else if(_Y1 >= aktuellerDigitalwert && aktuellerDigitalwert > _Y2)
        return blau(aktuellerDigitalwert);
      else if(_Y2 >= aktuellerDigitalwert && aktuellerDigitalwert > _Y3)
        return rot(aktuellerDigitalwert);
      else if(_Y3 >= aktuellerDigitalwert && aktuellerDigitalwert > _Y4)
        return gruen(aktuellerDigitalwert);
      else
        return -1;
    }
  float blau(int y)
    {
      2022 11 21 - Linearisierung
      Montag, 21. November 2022 07:59
       2BKI21 INF Seite 1
    {
      return fVonY(y, _X1, _X2, _Y1, _Y2);
    }
    float rot(int y)
  {
      return fVonY(y, _X2, _X3, _Y2, _Y3);
  }
    float gruen(int y)
  {
      return fVonY(y, _X3, _X4, _Y3, _Y4);
  }
    float fVonY(int y, int x1, int x2, int y1, int y2)
  {
    float dy = (float)(y2 - y1);
    float dx = (float)(x2 - x1);
    float m = dy / dx;
    float b = (float)y1 - m * (float)x1;
    float x = ((float)y - b) / m;
      return x;
  }
  int fVonX(float x, int x1, int x2, int y1, int y2)
  {
  float dy = (float)(y2 - y1);
  float dx = (float)(x2 - x1);
  float m = dy / dx;
  float b = (float)y1 - m * (float)x1;
  int y = (int)(m * x + b);
  return y;
  }
  int volt2digi(float volt)
  {
  float erg = 4095 * volt / 3.3;
  return (int)erg;
  }

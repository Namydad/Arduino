#define _Name "Tobias Lammer"
#define _Date "23.Januar 2023"

//Prototypen
int automat1()

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    delay(1000);
    Serial.printf("Date: %s, Author: %s\n", _Date, _Name);
}

void loop() {
  // put your main code here, to run repeatedly:
    int z=automat1();
    Serial.printf("Zustand: %i\n", z);
}
int automat1() {
    return 0;
}
int zaehlautomat(){
    static int zustand = 0;

    switch(zustand){
        case 0: zustand = 1; break;

        case 1: zustand = 2; break;

        case 2: zustand = 0; break;

    }

    return zustand;

}
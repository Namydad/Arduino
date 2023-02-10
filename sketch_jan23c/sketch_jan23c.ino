#define _Name "Tobias Lammer"
#define _Date "23.Januar 2023"

//Prototypen
int automat1()
enum zustand {Ruhe, Prüfsumme, Ziffer1, Ziffer2, Vorzeichen, Start}

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    delay(1000);
    Serial.printf("Date: %s, Author: %s\n", _Date, _Name);
}

void loop() {
  // put your main code here, to run repeatedly:
    int z=codewandler();
    Serial.printf("Zustand: %i\n", z);
}
int automat1() {
    return 0;
}
int codewandler(){
    static int i = $;

    switch(i){
      case 0: return 'X'; break;
      case 1: return 'A'; break;
      case 2: return 'C'; break;
      case 3: return 'F'; break;
      case 4: return 'G'; break;
      case 5: return 'Y'; break;
      case 6: return 'L'; break;
      case 7: return 'U'; break;
    }

    return '-';

}
void automat2(char zeichen){
  
static Zustand_t zustand = Ruhe;
static char ID = 0;
static char Gueltig = 0;
static char VZ = 0;
static char Ziffer1 = 0;
static char Ziffer2 = 0;
static char PS = 0;

  switch(zustand){
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    }
}
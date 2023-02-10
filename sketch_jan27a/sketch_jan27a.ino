#define _Name "Tobias"
#define _Date "2023-27-01"
#define _A_PIN 0
#define _F_PIN 1
#define _H_PIN 2

void loop (zustand){
    int tmp = maschine();
    int a_wert = A_gedrueckt
    int f_wert = F_gedrueckt
    
    Serial.begin(115200);
    Serial.printf("Taster 2: %i\n F Taster: %i\n", a_wert, f_wert)
    
}
int A_gedrueckt(){
    return !digitalRead(_A_PIN);
}
int F_gedrueckt(){
    return digitalRead(_F_PIN);
}
int H_gedrueckt(){
    return digitalRead(_H_PIN);
}

str maschine(zustand){
    static str zustand = "";
    static int GN = 0;
    static int RT = 0;
    int A = A_gedrueckt();
    int H = H_gedrueckt();
    int F = F_gedrueckt();

    switch(zustand){
      case FrequenzAendern: 
            if ( F == 0)
                F = 1; 
            else if ( F == 1 )
                F = 0;
                if ( GN == 1)
                    zustand = GruenGewaehlt;
                else if ( RT == 1 )
                    zustand = RotGewaehlt;
            break;
      case HelligkeitAendern:
            if ( H == 0)
                H = 1; 
            else if ( H == 1 )
                H = 0;
                if ( GN == 1)
                    zustand = GruenGewaehlt;
                else if ( RT == 1 )
                    zustand = RotGewaehlt;
            break;
      case GruenGewaehlt:
            if ( A == 1 )
                zustand = WarteVorBlinen;
            break;
      case RotGewaehlt:
            if ( A == 1 )
                zustand = WarteVorBlinen;
            break;
      case WarteVorBlinken: return 'Y'; break;
      case WarteNachBlinken: return 'L'; break;
      case Blinken: return 'U'; break;
    }

    return '-';

}
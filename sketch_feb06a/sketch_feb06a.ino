ich#define _Name "Tobias"
#define _Date "2023-06-02"
#define _Topic "Arrays"

//Variables 
int numbers[8];

void setup(){
    Serial.begin(115200);
    delay(500);
    Serial.printf("Setup");
    Serial.printf("Author: %s\n Datum: %s\n Thema: %s\n ", _Name, _Date, _Topic);
    aufgabe2MitZufallszahlenZwischen(-20,50);
    aufgabe2mitfestenzahlen();
    printArray(numbers[8]);
}

void printArray (String nameofarray, int* arrayinput){
    for (int i = 0; i < 8; i++) {
      Serial.printf("%s: %3i", nameofarray.c_str(), arrayinput[i]);
    }
    Serial.printf("\n");
}
void aufgabe2mitfestenzahlen(){
    int numbers [0] = 17;
    int numbers [1] = 21;
    int numbers [2] = 12;
    int numbers [3] = 13;
    int numbers [4] = 17;
    int numbers [5] = 50;
    int numbers [6] = 1;
    int numbers [7] = 7;
}
void aufgabe2MitZufallszahlenZwischen(int minimum, int maxium){
    int numbers [0] = random(int minimum, int maximum);
    int numbers [1] = random(int minimum, int maximum);
    int numbers [2] = random(int minimum, int maximum);
    int numbers [3] = random(int minimum, int maximum);
    int numbers [4] = random(int minimum, int maximum);
    int numbers [5] = random(int minimum, int maximum);
    int numbers [6] = random(int minimum, int maximum);
    int numbers [7] = random(int minimum, int maximum);
  
}

#include <Serial.h>

const int redPin = 13;
const int greenPin = 15;

int state = 0;
int redBrightness = 0;
int greenBrightness = 0;
int frequency = 1;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  maschine();
  String output = "State: " + String(state) + ", Red Brightness: " + String(redBrightness) + ", Green Brightness: " + String(greenBrightness) + ", Frequency: " + String(frequency);
  Serial.println(output);
}

void maschine() {
  switch (state) {
    case 0: // Rot gewählt
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      break;
    case 1: // Grün gewählt
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      break;
    case 2: // Frequenz ändern
      frequency = changeFrequency();
      break;
    case 3: // Helligkeit ändern
      redBrightness = changeBrightness(redBrightness);
      greenBrightness = changeBrightness(greenBrightness);
      break;
    case 4: // Warten vor Blinken
      delay(1000 / frequency);
      break;
    case 5: // Blinken
      digitalWrite(redPin, !digitalRead(redPin));
      digitalWrite(greenPin, !digitalRead(greenPin));
      break;
    case 6: // Warten nach Blinken
      delay(1000 / frequency);
      break;
    case 7: // Warten auf Knopfdruck
      if (Serial.available()) {
        state = (state + 1) % 8;
      }
      break;
  }
}

int changeFrequency() {
  // Code zur Änderung der Frequenz
  return frequency;
}

int changeBrightness(int brightness) {
  // Code zur Änderung der Helligkeit
  return brightness;
}

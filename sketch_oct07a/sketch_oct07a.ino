/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/

#define _DATUM "2022 09 19"
#define _AUTOR "Namydad"

//float soft_version = 951.678f;
//soft_version = truncf(soft_version * 10.0) / 10.0;

float soft_version = 951.678;

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

#define _ANALOG_PIN A0

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  int x ; // dies ist eine lokale variable

  x = soft_version;
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  delay(1000);

  Serial.printf("Datum: %s Auto: %s\n Version: %i\n", _DATUM, _AUTOR, x);
  //Serial.printf("Datum: %s Auto: %s\n Version: %5.2f\n", _DATUM, _AUTOR, soft_version);
}

void loop() {
  int digi;
  float prozent = 0;
  digi = analogRead(A0); 
  prozent = map(digi, 0, 4095, 0, 1000);
  prozent = prozent / 10; 
  Serial.printf("digi: %i - Prozent %4.2f%%\n", digi, prozent);
  delay(250);
}

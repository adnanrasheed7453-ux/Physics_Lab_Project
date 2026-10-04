/*
  Alarm System - House Protection
  First Semester Physics Lab Project
  Superior University Lahore - BS Cybersecurity

  NOTE: This is a reconstructed version of the original project code.

  Board  : Arduino Uno
  Sensor : PIR Motion Sensor (HC-SR501) -> OUT connected to Digital Pin 2
  Output : Active Buzzer                -> (+) connected to Digital Pin 8
*/

const int pirPin    = 2;   // PIR sensor OUT pin
const int buzzerPin = 8;   // Buzzer positive (+) pin

const unsigned long warmUpTime   = 30000; // PIR warm-up: 30 seconds
const unsigned long alarmTime    = 5000;  // Alarm sounds for 5 seconds
const int           beepOnTime   = 200;   // Buzzer ON  for 200 ms
const int           beepOffTime  = 100;   // Buzzer OFF for 100 ms

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);
  Serial.println("Alarm System - House Protection");
  Serial.println("Warming up PIR sensor (30 seconds)...");

  delay(warmUpTime);

  Serial.println("System ARMED. Monitoring for motion...");
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    Serial.println("ALERT: Motion detected! Alarm ON");
    soundAlarm();
    Serial.println("Alarm OFF. Monitoring again...");
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}

// Beeps the buzzer repeatedly for the alarm duration
void soundAlarm() {
  unsigned long startTime = millis();

  while (millis() - startTime < alarmTime) {
    digitalWrite(buzzerPin, HIGH);
    delay(beepOnTime);
    digitalWrite(buzzerPin, LOW);
    delay(beepOffTime);
  }
  digitalWrite(buzzerPin, LOW);
}

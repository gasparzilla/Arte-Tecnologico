#include <CapacitiveSensor.h>

const int led = 10;

CapacitiveSensor cs1 = CapacitiveSensor(8,9);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

bool illuminating = false;

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  if ((sensor1 > 1000) and (not illuminating)) {
    illuminating = true;
    digitalWrite(led, HIGH);
  }
  if ((sensor1<1000) and (illuminating)){
    digitalWrite(led, LOW);
    illuminating = false;
  }
}

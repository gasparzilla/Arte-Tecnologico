#include <CapacitiveSensor.h>

CapacitiveSensor cs1 = CapacitiveSensor(8,9);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

bool printing = false;

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  if ((sensor1 > 1000) and (not printing)) {
    printing = true;
    Serial.println("Hola!");
  }
  if (sensor1<1000){
    printing = false;
  }
}

#include <CapacitiveSensor.h>

CapacitiveSensor cs1 = CapacitiveSensor(8,9);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  Serial.println(sensor1);
}

#include <CapacitiveSensor.h>
#include <Servo.h>

const int led = 10;

CapacitiveSensor cs1 = CapacitiveSensor(8,9);
Servo myServo;

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  myServo.attach(3);
}

bool moving = false;

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  if ((sensor1 > 800) and (not moving)) {
    moving = true;
    myServo.write(180);
    delay(100);
  }
  if ((sensor1<800) and (moving = true)){
    moving = false;
    myServo.write(0);
    delay(100);
  }
}

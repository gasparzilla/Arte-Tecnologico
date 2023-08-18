#include <CapacitiveSensor.h>
// Incluir la libreria Servo.h para poder controlar
// un servomotor
#include <Servo.h>

CapacitiveSensor cs1 = CapacitiveSensor(16,10);
// Definir el servo que vamos a controlar
Servo myServo;

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  // Inicializar el servo a utilizar, asociandolo a un pin PWM
  // 	myServo.attach(pin_PWM)
  //
  //    pin PWM disponible = 3,5,6,9,10
  myServo.attach(3);
}

// Variable de estado para el motor
bool motor_activado = false;

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  // Si el sensor se activa y el servo no se ha activado
  if ((sensor1 > 1000) and (not motor_activado)) {
  	// Mover el servo en algun angulo
    myServo.write(180);
    // Darle tiempo al Servo para llegar a su obetivo
    delay(100);
    // Cambiar el valor de la variable de estado
    motor_activado = true;

  }
  // Si el sensor se desactiva y el servo estaba activado
  if ((sensor1<1000) and (motor_activado)){
  	// Mover el servo a su posicion original
    myServo.write(0);
    // Darle tiempo al Servo para llegar a su obetivo
    delay(100);
    // Cambiar el valor de la variable de estado
    motor_activado = true;
  }
}

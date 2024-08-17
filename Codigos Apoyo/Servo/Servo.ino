// Uso Servomotor

// Incluir libreria
#include <Servo.h>

// Inicializar Servo
Servo myServo;

// Definir pin digital para controlar el servo
const int servoPin = 9;

// Configuracion Inicial
void setup() {
  myServo.attach(servoPin);
  myServo.write(0);  // Inicializa el servomotor en 0 grados
  delay(200);
}

void loop() {
  myServo.write(90);  // Mueve el servomotor a 90 grados
  delay(1000);        // Espera 1 segundo
  
  myServo.write(0);   // Mueve el servomotor de vuelta a 0 grados
  delay(1000);        // Espera 1 segundo
}

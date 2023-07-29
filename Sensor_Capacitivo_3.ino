#include <CapacitiveSensor.h>

// Definir el pin a utilizar para el led
const int led = 10;

CapacitiveSensor cs1 = CapacitiveSensor(8,9);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  // Inicializar el pin del led en modo OUTPUT
  pinMode(led, OUTPUT);
}

// Definir una variable de estado para saber si
// el led està encendido o no
bool led_encendido = false;

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  // Si el sensor se activa y el led no esta encendido
  if ((sensor1 > 1000) and (not led_encendido)) {
    // Encender el led
    digitalWrite(led, HIGH);
    // Cambiar la variable de estado
    led_encendido = true;
  }
  // Si el sensor se desactiva y el led esta encendido
  if ((sensor1<1000) and (led_encendido)){
    // Apagar el led
    digitalWrite(led, LOW);
    // Cambiar la variable de estado
    led_encendido = false;
  }
}

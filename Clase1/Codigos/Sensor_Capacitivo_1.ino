// Incluir Librerias 
//	 CapacitiveSensor: permite utilizar sensores 
//   capacitivos para realizar multiples acciones
#include <CapacitiveSensor.h>

// Definir el sensor capacitivoa utilizar
//     CapacitiveSensor(pin1, pin2)
CapacitiveSensor cs1 = CapacitiveSensor(8,9);

// Setup, inicializacion del arduino
void setup() {
  //  Inicializar el sensor capacitivo y autocalibrar
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  //  Inicializar comunicacion serial 
  Serial.begin(9600);
}

// Loop, ejecucion del codigo
void loop() {
  // Lectura del sensor capacitivo previamente definido
  long sensor1 = cs1.capacitiveSensor(50);
  // Mostrar el valor del sensor en el monitor serial
  Serial.println(sensor1);
}

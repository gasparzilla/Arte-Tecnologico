// Incluir Librerias 
//	 CapacitiveSensor: permite utilizar sensores 
//   capacitivos para realizar multiples acciones
#include <CapacitiveSensor.h>

// Definir el sensor capacitivo a utilizar
//     CapacitiveSensor(pin_emisor, pin_receptor)
//     Una resistencia de 1M va entre los dos pines
//     Un cable va al pin_receptor
CapacitiveSensor cs1 = CapacitiveSensor(16,10);

// Setup, inicializacion del arduino
void setup() {
  // Inicializar el sensor capacitivo y  detener
  // recalibracion
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  //  Inicializar comunicacion serial 
  Serial.begin(9600);
}

// Loop, ejecucion del codigo
void loop() {
  // Lectura del sensor capacitivo previamente definido
  // sensor..capacitiveSensor(int: tasa de refresco);
  long sensor1 = cs1.capacitiveSensor(50);
  // Mostrar el valor del sensor en el monitor serial
  Serial.println(sensor1);
}

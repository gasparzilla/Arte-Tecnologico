#include <CapacitiveSensor.h>

CapacitiveSensor cs1 = CapacitiveSensor(16,10);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

// Variable de estado para saber si se acaba
// de imprimir una frase en el monitor serial
bool mensaje_escrito = false;

// Mensaje que mostraremos en la pantalla
String mensaje = "Hola!!!";

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  // Si el sensor esta activado, y no se ha
  // escrito nada en el monitor
  if ((sensor1 > 1000) and (not mensaje_escrito)) {
	// Imprimir el mensaje en el monitor serial
    Serial.println(mensaje);
  	// cambiar el estado de la variable de estado
  	// para no imprimir infinitamente
    mensaje_escrito = true;
  }
  // Si el sensor se desactiva
  if (sensor1<1000){
  	// Cambair el valor de la variable de estado
  	// para poder imprimir el mensaje la proxima 
  	// vez que se active
    mensaje_escrito = false;
  }
}

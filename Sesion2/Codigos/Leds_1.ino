// Incluir libreria FastLed para controlar las
// tiras LED
#include "FastLED.h"

// Definir el numero de leds a uilizar
#define N_LEDS 60
// Inicializar arreglo para controlar leds
CRGB leds[N_LEDS];
// Definir pin para control de leds
#define pinLed 6

// configuracion
void setup(){
  // inicializar cinta de leds
  // 	  metodo FastLED.addLeds 
  //      Configuracion   < Tipo de led       = WS2811 ,
  //      Fisica            Pin digital       = PIN    ,
  //                        Modo              = GRB    >
  //      ----------------------------------------------
  //      Configuracion   ( Lista de LEDs     = leds   ,
  //      Variables         Cantidad LEDs     = N_LEDS )
  //      ----------------------------------------------
  //      Correcion de color: corrige la proporcion
  //      de los colores para que se perciban de m-
  //      anera correcta
  //                      .setCorrection(TypicalLEDStrip)
  FastLED.addLeds<WS2811, pinLed, GRB>(leds, N_LEDS).setCorrection( TypicalLEDStrip );
}

void loop(){
	// Definir el LED a controlar
	int pixel = 0
	// Definir los colores a utilizar
	// color = 0 -> 255
	int rojo  = 100;
	int verde = 100;
	int azul  = 100;
	// Cambiar la luz de un led
	leds[pixel].r = red;
	leds[pixel].g = green;
	leds[pixel].b = blue;
	// mostrar el cambio en la tira LED
	FastLED.show();
}

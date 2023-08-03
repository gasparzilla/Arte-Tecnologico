#include "FastLED.h"

#define N_LEDS 60
CRGB leds[N_LEDS];
#define pinLed 6

void setup(){
  FastLED.addLeds<WS2811, pinLed, GRB>(leds, N_LEDS).setCorrection( TypicalLEDStrip );
}

void loop(){
	// Cambiar los colores de todos los leds con una funcion
	// definida por nosotros
	cambiar_LEDs(25, 50, 75);	
	// Mostrar el cambio en la tira LED
	FastLED.show();
	// Una pausa
	delay(100);
}

// Definir una funcion para cambiar el color de un led 
void cambiar_LED(int pixel, int rojo, int verde, int azul){
	leds[pixel].r = rojo;
	leds[pixel].g = verde;
	leds[pixel].b = azul;
}

// Definir una funcion para cambiar el color de todos los leds
void cambiar_LEDs(int rojo, int verde, int azul){
	for (int i = 0; i < N_LEDS; i++){
		cambiar_LED(i, rojo, verde, azul);
	}
}

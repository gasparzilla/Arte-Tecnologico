#include "FastLED.h"

#define N_LEDS 60
CRGB leds[N_LEDS];
#define pinLed 6

void setup(){
  FastLED.addLeds<WS2811, pinLed, GRB>(leds, N_LEDS).setCorrection( TypicalLEDStrip );
}

void loop(){
	int rojo  = 100;
	int verde = 100;
	int azul  = 100;
	// Cambiar el color de todos los leds
	// Para todos los leds
	for (int i = 0; i < N_LEDS; i++)
		// Cambiar la luz del led correspondiente
		leds[pixel].r = rojo;
		leds[pixel].g = verde;
		leds[pixel].b = azul;
	// Mostrar el cambio en la tira LED
	FastLED.show();
	// Una pausa
	delay(100);
}

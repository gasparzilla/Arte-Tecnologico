#include "FastLED.h"

#define N_LEDS 60
CRGB leds[NUM_LEDS];
#define PIN 6

void setup(){
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
}

void loop(){

}

void cambiar_LED(int pixel, int rojo, int verde, int azul){
	leds[pixel].r = rojo;
	leds[pixel].g = verde;
	leds[pixel].b = azul;
}

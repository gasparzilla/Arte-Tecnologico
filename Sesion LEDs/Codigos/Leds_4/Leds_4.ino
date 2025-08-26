#include <FastLED.h>

#define N_LEDS 60
CRGB leds[N_LEDS];
#define pinLed 6

void setup(){
  FastLED.addLeds<WS2811, pinLed, GRB>(leds, N_LEDS).setCorrection( TypicalLEDStrip );
}

void loop(){

}

void cambiar_LED(int pixel, int rojo, int verde, int azul){
	leds[pixel].r = rojo;
	leds[pixel].g = verde;
	leds[pixel].b = azul;
}

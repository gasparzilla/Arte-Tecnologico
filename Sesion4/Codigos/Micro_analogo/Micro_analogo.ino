#include "FastLED.h"

#define N_LEDS 18
CRGB leds[N_LEDS];
#define pinLed 6

// Definir el pin a utilizar por el microfono
#define pinMic A0

int volumen = 0;

void setup(){
  FastLED.addLeds<WS2811, pinLed, GRB>(leds, N_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(9600);
}

void loop(){
  // Leer el valor del microfono digital
  int microfono = analogRead(pinMic);
  Serial.println(microfono);
  int encenderLeds = map(microfono, 450, 850, 0, N_LEDS);
  // Correccion para no pasarse de la cantidad de LEDs
  if (encenderLeds < 0 ){
    encenderLeds = 0;
  }
  if (encenderLeds > N_LEDS){
  	encenderLeds = N_LEDS;
  }
  // Encender los LEDs dependiendo del volumen
  for (int i = 0; i < encenderLeds; i++){
    // Si los leds encendidos son los primeros 10
    // encender en verde
    if (i<10){
      cambiar_LED(i, 0, 175, 0);
    }
    // Si los leds encendidos son del 11 al 13
    // encender en amarillo
    else if ((i>=10) && (i<13)){
      cambiar_LED(i, 125, 125, 0);
    }
    // Si los leds encendidos son del 14 al 15
    // Encender en Rojo
    else {
      cambiar_LED(i, 175, 0, 0);
    }
  }
  // Apagar los LEDs dependiendo del volumen
  for (int i = N_LEDS-1; i < 15; i++){
    cambiar_LED(i, 0, 0, 0);
    }
  // Mostrar los leds encendidos en la tira led
  FastLED.show();
}

void cambiar_LED(int pixel, int rojo, int verde, int azul){
  leds[pixel].r = rojo;
  leds[pixel].g = verde;
  leds[pixel].b = azul;
}

#include <CapacitiveSensor.h>
// incluir lalibreria para poder enviar señales MIDI
#include <MIDIUSB.h>

CapacitiveSensor cs1 = CapacitiveSensor(8,9);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

// Variable de estado para saber si ya se eimitio una nota
bool nota = false;

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  // Si el sensor está activado y no se ha enviado una nota
  // por midi
  if ((sensor1 > 1000) and (not nota)) {
  	// Definir el mensaje midi a enviar
  	// 		tipo de variable: midiEventPacket_t
  	//      estructura:{Evento MIDI:  0x09 -> Note On  ,
  	//					Comando MIDI: 0x90 -> Note On  |
  	//					Canal:        0 -> 8           ,
    //                  Nota:         0 -> 127         ,
    //                  Velocidad:    0 -> 127         }
    midiEventPacket_t noteOn = {0x09, 0x90 | 0, 64, 64};
    // Enviar el mensaje MIDI
    MidiUSB.sendMIDI(noteOn);
    // Nos aseguramos que el mensaje se haya enviado
    MidiUSB.flush();
    // Cambiar el valor de la variable de estado
    nota = true;
  }
  // Si el sensor se desactivo y se habia enviado una nota
  // por midi
  if ((sensor1<1000) and (nota)){
    // Definir el mensaje midi a enviar
  	// 		tipo de variable: midiEventPacket_t
  	//      estructura:{Evento MIDI:  0x08 -> Note Off ,
  	//					Comando MIDI: 0x80 -> Note On  |
  	//					Canal:        0 -> 8           ,
    //                  Nota:         0 -> 127         ,
    //                  Velocidad:    0                }
    //		El canal y nota tienen que ser los mismos que
    //      se encendieron anteriormente
    midiEventPacket_t noteOff = {0x08, 0x80 | 0, 64, 0};
    // Enviar el mensaje MIDI
    MidiUSB.sendMIDI(noteOff);
    // Nos aseguramos que el mensaje se haya enviado
    MidiUSB.flush();
    // Cambiar el valor de la variable de estado
    nota = false;
  }
}

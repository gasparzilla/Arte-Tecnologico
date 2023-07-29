#include <CapacitiveSensor.h>
#include <MIDIUSB.h>

CapacitiveSensor cs1 = CapacitiveSensor(8,9);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

bool nota = false;

void loop() {
  long sensor1 = cs1.capacitiveSensor(50);
  Serial.println(sensor1);
  if ((sensor1 > 1000) and (not nota)) {
    nota = true;
    midiEventPacket_t noteOn = {0x09, 0x90 | 0, 64, 64};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
  }
  if ((sensor1<1000) and (nota)){
    nota = false;
    midiEventPacket_t noteOff = {0x08, 0x80 | 0, 64, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
}

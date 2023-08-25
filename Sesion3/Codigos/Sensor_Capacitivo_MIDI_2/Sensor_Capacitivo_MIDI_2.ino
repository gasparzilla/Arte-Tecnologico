#include <CapacitiveSensor.h>
#include <MIDIUSB.h>

CapacitiveSensor cs1 = CapacitiveSensor(16,10);
CapacitiveSensor cs2 = CapacitiveSensor(15,14);
CapacitiveSensor cs3 = CapacitiveSensor(A1,A0);
CapacitiveSensor cs4 = CapacitiveSensor(A3,A2);

void setup() {
  cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

bool t1 = false;
bool t2 = false;
bool t3 = false;
bool t4 = false;

void loop() {
  // nota 1
  long sensor1 = cs1.capacitiveSensor(50);
  if ((sensor1 > 1000) and (not t1)) {
    t1 = true;
    midiEventPacket_t noteOn = {0x09, 0x90 | 0, 40, 64};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
  }
  if ((sensor1<1000) and (t1)){
    t1 = false;
    midiEventPacket_t noteOff = {0x08, 0x80 | 0, 40, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
  // nota 2
  long sensor2 = cs2.capacitiveSensor(50);
  if ((sensor2 > 1000) and (not t2)) {
    t2 = true;
    midiEventPacket_t noteOn = {0x09, 0x90 | 0, 45, 64};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
  }
  if ((sensor2<1000) and (t2)){
    t2 = false;
    midiEventPacket_t noteOff = {0x08, 0x80 | 0, 45, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
  // nota 3
  long sensor3 = cs3.capacitiveSensor(50);
  if ((sensor3 > 1000) and (not t3)) {
    t3 = true;
    midiEventPacket_t noteOn = {0x09, 0x90 | 0, 50, 64};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
  }
  if ((sensor3<1000) and (t3)){
    t3 = false;
    midiEventPacket_t noteOff = {0x08, 0x80 | 0, 50, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
   // nota 4
  long sensor4 = cs4.capacitiveSensor(50);
  if ((sensor4 > 1000) and (not t4)) {
    t4 = true;
    midiEventPacket_t noteOn = {0x09, 0x90 | 0, 55, 64};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
  }
  if ((sensor4<1000) and (t4)){
    t4 = false;
    midiEventPacket_t noteOff = {0x08, 0x80 | 0, 55, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
}

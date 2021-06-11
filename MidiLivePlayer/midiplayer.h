#pragma once

#include "mididevice.h"
#include "keyboard.h"

// Class to bind a MidiDevice and a Keyboard together
class MidiPlayer {
public:

	MidiDevice device;
	Keyboard keyboard;

	MidiPlayer(uint8_t instrument);
};
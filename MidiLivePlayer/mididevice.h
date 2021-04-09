#pragma once

#include <cstdint>
#include "midihandle.h"



class MidiDevice {
private:
	MidiHandle deviceHandle;
	uint8_t volume;
	uint8_t duration;
	uint8_t channel;

	void SetInstrument(uint8_t instrument);
	void SendMidiMsg(uint32_t command);

public:
	MidiDevice(uint8_t volume = 127, uint8_t duration = 1000, 
				uint8_t instrument = 0, uint8_t deviceId = 0);
	void PlayNote(uint8_t note);
	uint32_t NotePack(uint8_t note, uint8_t volume);
};

#pragma once

#include <cstdint>
#include "midihandle.h"



class MidiDevice {
private:
	MidiHandle deviceHandle;
	uint8_t volume;
	uint32_t duration;
	uint8_t channel;


	uint32_t NotePack(uint8_t note, uint8_t volume);
	void SendMidiMsg(uint32_t command);

public:
	MidiDevice(uint8_t volume = 127, uint32_t duration = 1000, 
				uint8_t instrument = 0, uint8_t deviceId = 0);
	void SetInstrument(uint8_t instrument);
	void PlayNote(uint8_t note);
	void PlayNoteAsync(uint8_t note);
};

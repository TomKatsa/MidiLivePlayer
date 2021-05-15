#pragma once

#include <cstdint>
#include <optional>
#include "midihandle.h"

typedef std::optional<uint8_t> note_t;

class MidiDevice {
private:
	MidiHandle deviceHandle;
	uint8_t volume;
	uint32_t duration;


	uint32_t NotePack(uint8_t noteValue, uint8_t volume, uint8_t channel = 0);
	void SendMidiMsg(uint32_t command);

public:
	MidiDevice(uint8_t instrument = 0, uint8_t deviceId = 0, 
				uint8_t volume = 127, uint32_t duration = 1000);
	MidiDevice(const MidiDevice&) = delete;
	MidiDevice(MidiDevice&&);
	MidiHandle StealHandle();
	void SetInstrument(uint8_t instrument, uint8_t channel = 0);
	void PlayNoteOnce(note_t note);
	void PlayNoteOnceAsync(note_t note);
	void NoteDown(note_t note, int channel = 0);
	void NoteUp(note_t note, int channel = 0);
};


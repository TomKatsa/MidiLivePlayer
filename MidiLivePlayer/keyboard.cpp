#include <iostream>
#include <optional>
#include "keyboard.h"
#include "debugprint.h"

void Keyboard::RebaseKeyboard(note_t base) {
	if (!base.has_value()) {
		throw std::runtime_error("Base note value is empty");
	}

	unsigned int keyIndex = 0, noteValue = *base - 1;

	for (keyIndex, noteValue; keyIndex < keys.size(); keyIndex++, noteValue++) {
		if (keyIndex % 2 == 0 && (noteValue % 12 == 0 || noteValue % 12 == 5)) {
			// Skip a key
			keyIndex++;
		}

		LOG("[KEYBOARD] " << keys[keyIndex] << ": " << noteValue << std::endl);
		notes[keys[keyIndex]] = noteValue;
	}
}

Keyboard::Keyboard(MidiDevice midiDevice, note_t base) 
	: midiDevice(std::move(midiDevice)), base(base), notes(128, std::nullopt) {
	RebaseKeyboard(base);
}

note_t Keyboard::GetNote(char key) {
	return notes[key];
}

note_t Keyboard::operator[](char key)
{
	return GetNote(key);
}

void Keyboard::PlayKey(char key) {
	midiDevice.PlayNoteAsync(GetNote(key));
}



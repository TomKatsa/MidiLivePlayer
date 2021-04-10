#include <iostream>
#include "keyboard.h"
#include "debugprint.h"

void Keyboard::RebaseKeyboard(uint8_t base) {
	unsigned int key = 0, note = base - 1;

	for (key, note; key < keys.size(); key++, note++) {
		if (key % 2 == 0 && (note % 12 == 0 || note % 12 == 5)) {
			notes[key] = 0;
			key++;
		}

		LOG("[KEYBOARD] " << keys[key] << ": " << note << std::endl);
		notes[keys[key]] = note;
	}
}

Keyboard::Keyboard(uint8_t base) : base(base), notes(128) {
	RebaseKeyboard(base);
}

uint8_t Keyboard::GetNote(char key) {
	return notes[key];
}

uint8_t Keyboard::operator[](char key)
{
	return GetNote(key);
}



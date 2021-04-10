#pragma once

#include <cstdint>
#include <vector>
#include "mididevice.h"

class Keyboard {
private:
	MidiDevice midiDevice;
	note_t base;
	std::vector<note_t> notes;
	std::vector<char> keys { '1','q','2','w','3','e','4','r','5','t','6','y','7','u','8','i','9','o','0','p','-','[','=',']' };

	void RebaseKeyboard(note_t base);

public:
	Keyboard(MidiDevice midiDevice, note_t base = 60);
	note_t GetNote(char key);
	note_t operator[](char key);
	void PlayKey(char key);
};
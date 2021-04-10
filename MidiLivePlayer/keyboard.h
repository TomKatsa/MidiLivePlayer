#pragma once

#include <cstdint>
#include <vector>
#include "mididevice.h"

class Keyboard {
private:
	static Keyboard* thisPointer;
	MidiDevice midiDevice;
	note_t base;
	std::vector<note_t> notes;
	std::vector<char> keys { '1','q','2','w','3','e','4','r','5','t','6','y','7','u','8','i','9','o','0','p','-','[','=',']' };

	void RebaseKeyboard(note_t base);
	void InstallHook();
	static LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam);

public:
	Keyboard(MidiDevice midiDevice, note_t base = 60);
	~Keyboard();
	note_t GetNote(char key);
	note_t operator[](char key);
	void PlayKeyOnce(char key);
	void KeyDown(char key);
	void KeyUp(char key);
};
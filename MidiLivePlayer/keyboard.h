#pragma once

#include <cstdint>
#include <vector>
#include <mutex>
#include "mididevice.h"
#include "hook.h"

class Keyboard {
private:
	static Keyboard* thisPointer;
	Hook hookHandle;
	MidiDevice midiDevice;
	note_t base;
	std::vector<note_t> keys;
	static std::vector<bool> keysState;
	static std::mutex keysStateLock;
	// std::vector<char> layout { '1','q','2','w','3','e','4','r','5','t','6','y','7','u','8','i','9','o','0','p','-','[','=',']' };
	std::vector<char> layout { '1','Q','2','W','3','E','4','R','5','T','6','Y','7','U','8','I','9','O','0','P','-','[','=',']' };

	void RebaseKeyboard(note_t base);
	static LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam);

public:
	Keyboard(MidiDevice midiDevice, note_t base = 60);
	note_t GetNote(unsigned char key);
	note_t operator[](unsigned char key);
	void PlayKeyOnce(unsigned char key);
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
};
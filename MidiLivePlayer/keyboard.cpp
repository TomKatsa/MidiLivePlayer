#include <iostream>
#include <optional>
#include <thread>
#include <chrono>
#include <cassert>
#include "keyboard.h"
#include "debugprint.h"
#include "layout.h"

Keyboard* Keyboard::thisPointer = nullptr;
std::vector<bool> Keyboard::keysState(256, false);
std::mutex Keyboard::keysStateLock;

Keyboard::Keyboard(MidiDevice midiDevice, note_t base)
	: midiDevice(std::move(midiDevice)), base(base), 
	keys(256, std::nullopt), hookHandle(WH_KEYBOARD_LL, KeyboardProc), layout(Layout::layout) {

	RebaseKeyboard(base);
	thisPointer = this;
}

void Keyboard::RebaseKeyboard(note_t base) {
	assert(base.has_value());

	unsigned int keyIndex = 0, noteValue = *base - 1;

	for (keyIndex, noteValue; keyIndex < layout.size(); keyIndex++, noteValue++) {
		if (keyIndex % 2 == 0 && (noteValue % 12 == 0 || noteValue % 12 == 5)) {
			// Skip a key
			keyIndex++;
		}

		LOG("[KEYBOARD] " << layout[keyIndex] << ": " << noteValue << std::endl);
		keys[layout[keyIndex]] = noteValue;
	}
}

LRESULT Keyboard::KeyboardProc(int code, WPARAM wParam, LPARAM lParam) {
	assert(thisPointer);

	if (code == HC_ACTION)
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
		unsigned char key = p->vkCode;

		std::lock_guard<std::mutex> lock(Keyboard::keysStateLock);

		switch (wParam) {
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			if (!thisPointer->keysState[key]) {
				keysState[key] = true;
				thisPointer->KeyDown(p->vkCode);
			}
			break;

		case WM_KEYUP:
		case WM_SYSKEYUP:
			keysState[key] = false;
			thisPointer->KeyUp(p->vkCode);
			break;
		}
	}

	// Not processing keys so always return CallNextHookEx
	return(CallNextHookEx(NULL, code, wParam, lParam));
}

note_t Keyboard::GetNote(unsigned char key) {
	return keys[key];
}

note_t Keyboard::operator[](unsigned char key)
{
	return GetNote(key);
}

void Keyboard::PlayKeyOnce(unsigned char key) {
	midiDevice.PlayNoteOnceAsync(GetNote(key));
}

void Keyboard::KeyDown(unsigned char key) {
	midiDevice.NoteDown(GetNote(key));
}

void Keyboard::KeyUp(unsigned char key) {
	midiDevice.NoteUp(GetNote(key));
}

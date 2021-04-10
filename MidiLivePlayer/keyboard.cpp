#include <iostream>
#include <optional>
#include <thread>
#include <chrono>
#include <cassert>
#include "keyboard.h"
#include "debugprint.h"

Keyboard* Keyboard::thisPointer = nullptr;

Keyboard::Keyboard(MidiDevice midiDevice, note_t base)
	: midiDevice(std::move(midiDevice)), base(base), 
	  notes(128, std::nullopt), hookHandle(WH_KEYBOARD_LL, KeyboardProc) {

	RebaseKeyboard(base);
	thisPointer = this;
}

void Keyboard::RebaseKeyboard(note_t base) {
	assert(base.has_value());

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

LRESULT Keyboard::KeyboardProc(int code, WPARAM wParam, LPARAM lParam) {
	LOG("Entered KeyboardProc" << std::endl);
	if (thisPointer == nullptr) {
		throw std::runtime_error("this pointer is null");
	}

	if (code == HC_ACTION)
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

		switch (wParam) {
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			thisPointer->KeyDown(p->vkCode);
			// std::this_thread::sleep_for(std::chrono::milliseconds(200));
			break;
		case WM_KEYUP:
		case WM_SYSKEYUP:
			thisPointer->KeyUp(p->vkCode);
			break;
		}
	}

	// Not processing keys so always return CallNextHookEx
	return(CallNextHookEx(NULL, code, wParam, lParam));
}




note_t Keyboard::GetNote(char key) {
	return notes[key];
}

note_t Keyboard::operator[](char key)
{
	return GetNote(key);
}

void Keyboard::PlayKeyOnce(char key) {
	midiDevice.PlayNoteOnceAsync(GetNote(key));
}

void Keyboard::KeyDown(char key) {
	LOG("Received key " << key << std::endl);
	midiDevice.NoteDown(GetNote(key));
}

void Keyboard::KeyUp(char key) {
	midiDevice.NoteUp(GetNote(key));
}

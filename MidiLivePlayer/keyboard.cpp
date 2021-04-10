#include <iostream>
#include <optional>
#include "keyboard.h"
#include "debugprint.h"

Keyboard* Keyboard::thisPointer = nullptr;

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

void Keyboard::InstallHook() {
	thisPointer = this;
	HHOOK hookHandle = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, nullptr, 0);

	if (hookHandle == NULL) {
		throw std::runtime_error("Hook handle failed");
	}

	LOG("Installed keyboard hook");

}

LRESULT Keyboard::KeyboardProc(int code, WPARAM wParam, LPARAM lParam) {
	if (thisPointer == nullptr) {
		throw std::runtime_error("this pointer is null");
	}

	if (code == HC_ACTION)
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

		switch (wParam)
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			thisPointer->KeyDown(p->vkCode);
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


Keyboard::Keyboard(MidiDevice midiDevice, note_t base) 
	: midiDevice(std::move(midiDevice)), base(base), notes(128, std::nullopt) {

	RebaseKeyboard(base);
	InstallHook();
}

Keyboard::~Keyboard() {

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
	midiDevice.NoteDown(GetNote(key));
}

void Keyboard::KeyUp(char key) {
	midiDevice.NoteUp(GetNote(key));
}

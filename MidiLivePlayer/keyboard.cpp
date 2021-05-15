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

Keyboard::Keyboard(MidiDevice& midiDevice, note_t base)
	: midiDevice(midiDevice), base(base), 
	keys(256, std::nullopt), hookHandle(WH_KEYBOARD_LL, KeyboardProc), layout(Layout::layout) {

	// RebaseKeyboard(base);
	thisPointer = this;
}

LRESULT CALLBACK Keyboard::KeyboardProc(int code, WPARAM wParam, LPARAM lParam) {
	assert(thisPointer);
	try {
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
	}
	catch (std::out_of_range ex) {
		
	}
	catch (...) {
		LOG("Received unknown exception, aborting" << std::endl);
		abort();
	}

	// Not processing keys so always return CallNextHookEx
	return(CallNextHookEx(NULL, code, wParam, lParam));
}

void Keyboard::KeyDown(unsigned char key) {
	layout.at(key)->Down(midiDevice);
}

void Keyboard::KeyUp(unsigned char key) {
	layout.at(key)->Up(midiDevice);
}

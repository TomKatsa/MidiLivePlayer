#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <mutex>
#include "mididevice.h"
#include "hook.h"
#include "playable.h"

using Playable::IPlayable;

class Keyboard {
private:

	static Keyboard* thisPointer;
	Hook hookHandle;
	MidiDevice& midiDevice;
	note_t base;
	std::vector<note_t> keys;
	static std::vector<bool> keysState;
	static std::mutex keysStateLock;
	const std::map<unsigned char, std::shared_ptr<IPlayable>>& layout;

	static LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam);

public:
	Keyboard(MidiDevice& midiDevice);
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
};
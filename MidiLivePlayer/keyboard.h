#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <mutex>
#include "mididevice.h"
#include "hook.h"
#include "playable.h"
#include "layout.h"

using Playable::IPlayable;

/**
 * @brief Represents a keyboard, and defines a keyboard hook.
*/
class Keyboard {
private:

	// Passed to the hook callback to be able to use instance of the keyboard.
	static Keyboard* thisPointer;

	Hook hookHandle;
	MidiDevice& midiDevice;
	note_t base;
	std::vector<note_t> keys;

	// Maintain a state of each key - 1 for pressed, 0 for released.
	static std::vector<bool> keysState;

	// Prevent races when modifying the state of keys.
	static std::mutex keysStateLock;

	// Map of keys and notes
	const LayoutDict& layout;

	/**
	 * @brief Keyboard hook callback. Called every time a key is pressed down or released
	 * on the keyboard.
	*/
	static LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam);

public:
	Keyboard(MidiDevice& midiDevice);

	/**
	 * @brief Function to handle key pressed down.
	*/
	void KeyDown(unsigned char key);

	/**
	 * @brief Function to handle key released.
	*/
	void KeyUp(unsigned char key);
};
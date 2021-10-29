#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include "debugprint.h"

/**
 * @brief Wrapper class for a handle to a windows MIDI object. Managed with ctor and dtor
*/
class MidiHandle {

private:
	HMIDIOUT device;

public:
	MidiHandle(UINT deviceId = 0);
	~MidiHandle();
	MidiHandle(const MidiHandle&) = delete;
	MidiHandle(MidiHandle&&);
	HMIDIOUT Release();

	HMIDIOUT getHandle();

};
#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include "debugprint.h"

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
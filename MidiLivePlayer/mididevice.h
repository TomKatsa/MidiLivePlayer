#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include "debugprint.h"

class MidiDevice {

private:
	HMIDIOUT device;

public:
	MidiDevice(UINT deviceId = 0);
	~MidiDevice();

};
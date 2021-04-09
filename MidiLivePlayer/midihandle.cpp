#include "midihandle.h"
#include "exceptions.h"

MidiHandle::MidiHandle(UINT deviceId) {
	MMRESULT err = midiOutOpen(&this->device, deviceId, NULL, 0, CALLBACK_NULL);

	if (err != MMSYSERR_NOERROR) {
		throw MidiException(err);
	}

	LOG("MidiHandle created" << std::endl);
}

MidiHandle::~MidiHandle() {
	if (midiOutReset(this->device) != MMSYSERR_NOERROR) {
		LOG("[*] midiOutReset failed");
	}

	if (midiOutClose(this->device) != MMSYSERR_NOERROR) {
		LOG("[*] midiOutReset failed");
	}

	LOG("MidiHandle destroyed" << std::endl);
}

HMIDIOUT MidiHandle::getHandle() {
	return device;
}

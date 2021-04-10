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
	if (this->device == nullptr) {
		return;
	}

	if (midiOutReset(this->device) != MMSYSERR_NOERROR) {
		LOG("[*] midiOutReset failed");
	}

	if (midiOutClose(this->device) != MMSYSERR_NOERROR) {
		LOG("[*] midiOutReset failed");
	}

	LOG("MidiHandle destroyed" << std::endl);
}

MidiHandle::MidiHandle(MidiHandle&& otherHandle) : device(otherHandle.Release()) {};

HMIDIOUT MidiHandle::Release() {
	// Yield the handle and nullify this object's handle
	HMIDIOUT temp = device;
	device = nullptr;
	return temp;
}

HMIDIOUT MidiHandle::getHandle() {
	return device;
}

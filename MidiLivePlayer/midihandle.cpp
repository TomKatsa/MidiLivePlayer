#include "midihandle.h"
#include "exceptions.h"

MidiHandle::MidiHandle(UINT deviceId) {
	MMRESULT err = midiOutOpen(&this->device, deviceId, NULL, 0, CALLBACK_NULL);

	if (err != MMSYSERR_NOERROR) {
		throw MidiHandleException(err);
	}

	PRINT("MidiHandle created" << std::endl);
}

MidiHandle::~MidiHandle() {
	if (midiOutReset(this->device) != MMSYSERR_NOERROR) {
		PRINT("[*] midiOutReset failed");
	}

	if (midiOutClose(this->device) != MMSYSERR_NOERROR) {
		PRINT("[*] midiOutReset failed");
	}

	PRINT("MidiHandle destroyed" << std::endl);
}

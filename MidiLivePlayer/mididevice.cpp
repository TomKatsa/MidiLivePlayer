#include "mididevice.h"
#include "exceptions.h"

MidiDevice::MidiDevice(UINT deviceId) {
	MMRESULT err = midiOutOpen(&this->device, deviceId, NULL, 0, CALLBACK_NULL);

	if (err != MMSYSERR_NOERROR) {
		throw MidiDeviceException(err);
	}

	PRINT("MidiDevice created" << std::endl);
}

MidiDevice::~MidiDevice() {
	if (midiOutReset(this->device) != MMSYSERR_NOERROR) {
		PRINT("[*] midiOutReset failed");
	}

	if (midiOutClose(this->device) != MMSYSERR_NOERROR) {
		PRINT("[*] midiOutReset failed");
	}

	PRINT("MidiDevice destroyed" << std::endl);
}

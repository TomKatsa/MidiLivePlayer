#include <Windows.h>
#include <vector>

class MidiDeviceException {
private:
	MMRESULT err;

public:
	MidiDeviceException(MMRESULT err = MMSYSERR_ERROR) : err(err) {};

	std::string ErrorString() {
		std::vector<char> buffer(256);

		midiOutGetErrorTextA(err, buffer.data(), buffer.size());
		std::string str(buffer.begin(), buffer.end());

		return str;
	}
};
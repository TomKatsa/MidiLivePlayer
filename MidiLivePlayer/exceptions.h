#include <Windows.h>
#include <vector>

class MidiHandleException {
private:
	MMRESULT err;

public:
	MidiHandleException(MMRESULT err = MMSYSERR_ERROR) : err(err) {};

	std::string ErrorString() {
		std::vector<char> buffer(256);

		midiOutGetErrorTextA(err, buffer.data(), buffer.size());
		std::string str(buffer.begin(), buffer.end());

		return str;
	}
};
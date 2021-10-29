#include <Windows.h>
#include <vector>

/**
 * @brief Exception class wrapper for Midi errors.
*/
class MidiException {
private:
	MMRESULT err;

public:
	MidiException(MMRESULT err = MMSYSERR_ERROR) : err(err) {};

	std::string ErrorString() const {
		std::vector<char> buffer(256);

		/**
		 * @brief Get the corresponding error text for a MIDI error.
		 * @return std::string
		*/
		midiOutGetErrorTextA(err, buffer.data(), buffer.size());
		std::string str(buffer.begin(), buffer.end());

		return str;
	}
};
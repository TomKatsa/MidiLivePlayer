#include <Windows.h>
#include <chrono>
#include <thread>
#include <future>
#include "mididevice.h"
#include "exceptions.h"

MidiDevice::MidiDevice(uint8_t volume, uint32_t duration, uint8_t instrument, uint8_t deviceId)
	: volume(volume), duration(duration), deviceHandle(deviceId), channel(0) {

	SetInstrument(instrument);
	LOG("MidiDevice created " << this << std::endl);
}



void MidiDevice::PlayNote(uint8_t note) {
	SendMidiMsg(NotePack(note, volume));
	std::this_thread::sleep_for(std::chrono::milliseconds(duration));
	SendMidiMsg(NotePack(note, 0));
	LOG("Played note " << static_cast<int>(note) << std::endl);
}

void MidiDevice::PlayNoteAsync(uint8_t note) {
	std::thread(&MidiDevice::PlayNote, this, note).detach();
}

uint32_t MidiDevice::NotePack(uint8_t note, uint8_t volume) {
	uint32_t command = 0x90;
	command |= channel;
	command |= (note << 8);
	command |= (volume << 16);

	return command;
}


void MidiDevice::SetInstrument(uint8_t instrument) {
		uint32_t command = (0x000000C0 | channel) | (instrument << 8);
		SendMidiMsg(command);
}

void MidiDevice::SendMidiMsg(uint32_t command) {
	MMRESULT err =  midiOutShortMsg(deviceHandle.getHandle(), command);

	if (err != MMSYSERR_NOERROR) {
		throw MidiException(err);
	}
}


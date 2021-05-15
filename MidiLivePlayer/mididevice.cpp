#include <Windows.h>
#include <chrono>
#include <thread>
#include <future>
#include <optional>
#include "mididevice.h"
#include "exceptions.h"
#include "debugprint.h"

MidiDevice::MidiDevice(uint8_t instrument, uint8_t deviceId, uint8_t volume,uint32_t duration)
	: volume(volume), duration(duration), deviceHandle(deviceId) {

	SetInstrument(instrument);
	LOG("MidiDevice created " << this << std::endl);
}

void MidiDevice::PlayNoteOnce(note_t note) {
	if (!note.has_value()) {
		return;
	}

	NoteDown(note);
	std::this_thread::sleep_for(std::chrono::milliseconds(duration));
	NoteUp(note);
	LOG("Played single note " << static_cast<int>(*note) << std::endl);
}

void MidiDevice::PlayNoteOnceAsync(note_t note) {
	std::thread(&MidiDevice::PlayNoteOnce, this, note).detach();
}

void MidiDevice::NoteDown(note_t note, int channel) {
	if (note.has_value()) {
		LOG("Pressing down note " << static_cast<int>(*note) << std::endl);
		SendMidiMsg(NotePack(*note, volume, channel));
	}
}

void MidiDevice::NoteUp(note_t note, int channel) {
	if (note.has_value()) {
		SendMidiMsg(NotePack(*note, 0, channel));
	}
}

uint32_t MidiDevice::NotePack(uint8_t noteValue, uint8_t volume, uint8_t channel) {
	uint32_t command = 0x90;
	command |= channel;
	command |= (noteValue << 8);
	command |= (volume << 16);

	return command;
}

MidiDevice::MidiDevice(MidiDevice&& device)
	: deviceHandle(device.StealHandle()), volume(device.volume), duration(device.duration) {}

MidiHandle MidiDevice::StealHandle()
{
	return std::move(deviceHandle);
}

void MidiDevice::SetInstrument(uint8_t instrument, uint8_t channel) {
		uint32_t command = (0x000000C0 | channel) | (instrument << 8);
		SendMidiMsg(command);
}

void MidiDevice::SendMidiMsg(uint32_t command) {
	MMRESULT err =  midiOutShortMsg(deviceHandle.getHandle(), command);

	if (err != MMSYSERR_NOERROR) {
		throw MidiException(err);
	}
}


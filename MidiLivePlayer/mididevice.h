#pragma once

#include <cstdint>
#include <optional>
#include "midihandle.h"

typedef std::optional<uint8_t> note_t;

/**
 * @brief Wrapper for a windows MIDI device.
*/
class MidiDevice {
private:
	MidiHandle deviceHandle;
	uint8_t volume;
	uint32_t duration;

	/**
	 * @brief Create a 32-bit MIDI message with given parameters.
	*/
	uint32_t NotePack(uint8_t noteValue, uint8_t volume, uint8_t channel = 0);

	/**
	 * @brief Send a MIDI message to the device.
	 * @param command - 32-bit MIDI message, generated using NotePack func
	*/
	void SendMidiMsg(uint32_t command);

public:
	MidiDevice(uint8_t instrument = 0, uint8_t deviceId = 0, 
				uint8_t volume = 127, uint32_t duration = 1000);
	MidiDevice(const MidiDevice&) = delete;
	MidiDevice(MidiDevice&&);

	/**
	 * @brief Used to release the ownership on the MIDI handle.
	 * @return moved MidiHandle object. Can be used in a move constructor for a different MidiHandle object
	*/
	MidiHandle StealHandle();

	/**
	 * @brief Change the instrument for a specific channel
	*/
	void SetInstrument(uint8_t instrument, uint8_t channel = 0);

	/**
	 * @brief Send a MIDI message to play a note (and release).
	 * Duration is controlled in the MidiDevice class.
	 * Blocking function
	*/
	void PlayNoteOnce(note_t note);

	/**
	 * @brief Send a MIDI message to play a note (and release).
	 * Duration is controlled in the MidiDevice class.
	 * Non-blocking function (runs in new thread).
	*/
	void PlayNoteOnceAsync(note_t note);

	/**
	 * @brief Press down a note. Non-blocking.
	*/
	void NoteDown(note_t note, int channel = 0);

	/**
	 * @brief Release a note. Non-blocking.
	*/
	void NoteUp(note_t note, int channel = 0);
};


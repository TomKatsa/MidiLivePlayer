#pragma once

#include "mididevice.h"
#include <vector>

namespace Playable {

	/**
	 * @brief Interface for an object that can be played on a key press (up or down).
	*/
	class IPlayable {
	public:
		IPlayable();
		virtual ~IPlayable() = default;
		virtual void Down(MidiDevice& device) = 0;
		virtual void Up(MidiDevice& device) = 0;

	};

	/**
	 * @brief Class for a single note playable object.
	*/
	class SingleNote : public IPlayable {
	private:
		note_t note;
		int channel;

	public:
		SingleNote() = default;
		SingleNote(note_t note, int channel = 0);
		virtual ~SingleNote() = default;
		void Down(MidiDevice& device);
		void Up(MidiDevice& device);
	};

	/**
	 * @brief Class for a multiple note playable object (3 notes that make up a chord).
	*/
	class Chord : public IPlayable {
	private:
		std::vector<note_t> notes;

	public:
		Chord() = default;
		Chord(std::vector<note_t> notes);
		virtual ~Chord() = default;
		void Down(MidiDevice& device);
		void Up(MidiDevice& device);
		// Factory methods for creating a major or minor chords, given a root note.
		static Chord MajorChord(note_t base);
		static Chord MinorChord(note_t base);
	};

}
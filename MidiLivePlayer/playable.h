#pragma once

#include "mididevice.h"
#include <vector>

namespace Playable {

	class IPlayable {
	public:
		IPlayable();
		virtual ~IPlayable() = default;
		virtual void Down(MidiDevice& device) = 0;
		virtual void Up(MidiDevice& device) = 0;

	};


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


	class Chord : public IPlayable {
	private:
		std::vector<note_t> notes;

	public:
		Chord() = default;
		Chord(std::vector<note_t> notes);
		virtual ~Chord() = default;
		void Down(MidiDevice& device);
		void Up(MidiDevice& device);
		static Chord MajorChord(note_t base);
		static Chord MinorChord(note_t base);
	};

}
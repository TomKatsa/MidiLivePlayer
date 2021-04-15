#include <vector>
#include "playable.h"

using namespace Playable;

IPlayable::IPlayable() {};

SingleNote::SingleNote(note_t note, int channel) : note(note), channel(channel) {}

void SingleNote::Down(MidiDevice& device) {
	device.NoteDown(note, channel);
}

void SingleNote::Up(MidiDevice& device) {
	device.NoteUp(note, channel);
}

Chord::Chord(std::vector<note_t> notes) : notes(notes) {}

void Chord::Down(MidiDevice& device) {
	for (auto note : notes) {
		device.NoteDown(note);
	}
}

void Chord::Up(MidiDevice& device) {
	for (auto note : notes) {
		device.NoteUp(note);
	}
}

Playable::Chord Chord::MajorChord(note_t base) {
	return Playable::Chord(std::vector<note_t>{*base, *base + 4, *base + 7});
}

Playable::Chord Chord::MinorChord(note_t base) {
	return Playable::Chord(std::vector<note_t>{*base, * base + 3, * base + 7});
}
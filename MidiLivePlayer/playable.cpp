#include "playable.h"

SingleNote::SingleNote(note_t note) : note(note) {};

void SingleNote::Down(MidiDevice& device) {
	device.NoteDown(note);
}

void SingleNote::Up(MidiDevice& device) {
	device.NoteUp(note);
}

Playable::Playable() {};

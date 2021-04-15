#pragma once

#include "playable.h"

auto MinorChordPtr(note_t base) {
	return std::make_shared<Playable::Chord>(Playable::Chord::MinorChord(base));
}

auto MajorChordPtr(note_t base) {
	return std::make_shared<Playable::Chord>(Playable::Chord::MajorChord(base));
}

auto SingleNotePtr(note_t note) {
	return std::make_shared<Playable::SingleNote>(note);
}

auto BlankPtr() {
	return std::make_shared<Playable::SingleNote>();
}
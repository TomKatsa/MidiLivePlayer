#include "utility.h"

std::shared_ptr<Playable::Chord> MinorChordPtr(note_t base) {
	return std::make_shared<Playable::Chord>(Playable::Chord::MinorChord(base));
}

std::shared_ptr<Playable::Chord> MajorChordPtr(note_t base) {
	return std::make_shared<Playable::Chord>(Playable::Chord::MajorChord(base));
}

std::shared_ptr<Playable::SingleNote> SingleNotePtr(note_t note, int channel) {
	return std::make_shared<Playable::SingleNote>(note, channel);
}

std::shared_ptr<Playable::SingleNote> BlankPtr() {
	return std::make_shared<Playable::SingleNote>();
}
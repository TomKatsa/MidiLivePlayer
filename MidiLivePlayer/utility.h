#pragma once

#include "playable.h"

std::shared_ptr<Playable::Chord> MinorChordPtr(note_t base);

std::shared_ptr<Playable::Chord> MajorChordPtr(note_t base);

std::shared_ptr<Playable::SingleNote> SingleNotePtr(note_t note, int channel = 0);

std::shared_ptr<Playable::SingleNote> BlankPtr();
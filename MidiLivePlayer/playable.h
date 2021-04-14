#pragma once

#include "mididevice.h"


class Playable {
public:
	Playable();
	virtual ~Playable() = default;
	virtual void Down(MidiDevice& device) = 0;
	virtual void Up(MidiDevice& device) = 0;

};

class SingleNote : public Playable {
private:
	note_t note;

public:
	SingleNote(note_t note);
	virtual ~SingleNote() = default;
	void Down(MidiDevice& device);
	void Up(MidiDevice& device);
};
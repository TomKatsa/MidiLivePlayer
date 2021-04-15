#pragma once

#include <vector>
#include <map>
#include <optional>
#include "mididevice.h"
#include "playable.h"
#include "utility.h"

using namespace Playable;

enum BaseNotes {
	C = 60, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B
};

namespace Layout {
	const std::map<unsigned char, std::shared_ptr<IPlayable>> layoutPiano
	{
		{'1', SingleNotePtr(59)},
		{'Q', SingleNotePtr(60)},
		{'2', SingleNotePtr(61)},
		{'W', SingleNotePtr(62)},
		{'3', SingleNotePtr(63)},
		{'E', SingleNotePtr(64)},
		{'4', BlankPtr()},
		{'R', SingleNotePtr(65)},
		{'5', SingleNotePtr(66)},
		{'T', SingleNotePtr(67)},
		{'6', SingleNotePtr(68)},
		{'Y', SingleNotePtr(69)},
		{'7', SingleNotePtr(70)},
		{'U', SingleNotePtr(71)},
		{'8', BlankPtr()},
		{'I', SingleNotePtr(72)},
		{'9', SingleNotePtr(73)},
		{'O', SingleNotePtr(74)},
		{'0', SingleNotePtr(75)},
		{'P', SingleNotePtr(76)},
	};

	const std::map<unsigned char, std::shared_ptr<IPlayable>> layoutAccordion{
		{'Q', SingleNotePtr(F)},
		{'A', MajorChordPtr(F)},
		{'Z', MinorChordPtr(F)},

		{'W', SingleNotePtr(C)},
		{'S', MajorChordPtr(C)},
		{'X', MinorChordPtr(C)},

		{'E', SingleNotePtr(G)},
		{'D', MajorChordPtr(G)},
		{'C', MinorChordPtr(G)},

		{'R', SingleNotePtr(D)},
		{'F', MajorChordPtr(D)},
		{'V', MinorChordPtr(D)},

		{'T', SingleNotePtr(A - 12)},
		{'G', MajorChordPtr(A - 12)},
		{'B', MinorChordPtr(A - 12)},

		{'Y', SingleNotePtr(E)},
		{'H', MajorChordPtr(E)},
		{'N', MinorChordPtr(E)},

		{'U', SingleNotePtr(B - 12)},
		{'J', MajorChordPtr(B - 12)},
		{'M', MinorChordPtr(B - 12)},

		{'I', SingleNotePtr(Gb)},
		{'K', MajorChordPtr(Gb)},
		{VK_OEM_COMMA, MinorChordPtr(Gb)},

		{'0', SingleNotePtr(Db)},
		{'0', MajorChordPtr(Db)},
		{'0', MinorChordPtr(66)},

	};

	const std::map<unsigned char, std::shared_ptr<IPlayable>> layoutCombined{
	{'Q', SingleNotePtr(F)},
	{'A', MajorChordPtr(F)},
	{'Z', MinorChordPtr(F)},

	{'W', SingleNotePtr(C)},
	{'S', MajorChordPtr(C)},
	{'X', MinorChordPtr(C)},

	{'E', SingleNotePtr(G)},
	{'D', MajorChordPtr(G)},
	{'C', MinorChordPtr(G)},

	{'R', SingleNotePtr(D)},
	{'F', MajorChordPtr(D)},
	{'V', MinorChordPtr(D)},

	{'T', SingleNotePtr(A - 12)},
	{'G', MajorChordPtr(A - 12)},
	{'B', MinorChordPtr(A - 12)},

	{'Y', SingleNotePtr(E)},
	{'H', MajorChordPtr(E)},
	{'N', MinorChordPtr(E)},

	{'U', SingleNotePtr(B - 12)},
	{'J', MajorChordPtr(B - 12)},
	{'M', MinorChordPtr(B - 12)},

	{'I', SingleNotePtr(Gb)},
	{'K', MajorChordPtr(Gb)},
	{VK_OEM_COMMA, MinorChordPtr(Gb)},

	{'1', SingleNotePtr(C)},
	{'2', SingleNotePtr(D)},
	{'3', SingleNotePtr(E)},
	{'4', SingleNotePtr(F)},
	{'5', SingleNotePtr(G)},
	{'6', SingleNotePtr(A)},
	{'7', SingleNotePtr(B)},
	{'8', SingleNotePtr(C + 12)},
	{'9', SingleNotePtr(D + 12)},
	{'0', SingleNotePtr(E + 12)},

	};

	auto layout = layoutCombined;
	// const std::vector<unsigned char> layout{ '1','Q','2','W','3','E','4','R','5','T','6','Y','7','U','8','I','9','O','0','P','-','[','=',']' };

};


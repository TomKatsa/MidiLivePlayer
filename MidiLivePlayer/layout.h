#pragma once

#include <vector>
#include <map>
#include <optional>
#include "mididevice.h"
#include "playable.h"
#include "utility.h"

using namespace Playable;

namespace Layout {
	const std::map<unsigned char, std::shared_ptr<IPlayable>> layout
	{
		{'1', MinorChordPtr(59)},
		{'Q', MinorChordPtr(60)},
		{'2', MinorChordPtr(61)},
		{'W', MinorChordPtr(62)},
		{'3', MinorChordPtr(63)},
		{'E', MinorChordPtr(64)},
		{'4', BlankPtr()},
		{'R', MinorChordPtr(65)},
		{'5', MinorChordPtr(66)},
		{'T', MinorChordPtr(67)},
		{'6', MinorChordPtr(68)},
		{'Y', MinorChordPtr(69)},
		{'7', MinorChordPtr(70)},
		{'U', MinorChordPtr(71)},
		{'8', BlankPtr()},
		{'I', MinorChordPtr(72)},
		{'9', MinorChordPtr(73)},
		{'O', MinorChordPtr(74)},
		{'0', MinorChordPtr(75)},
		{'P', MinorChordPtr(76)},
	};
	// const std::vector<unsigned char> layout{ '1','Q','2','W','3','E','4','R','5','T','6','Y','7','U','8','I','9','O','0','P','-','[','=',']' };

};


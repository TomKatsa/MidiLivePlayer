#pragma once

#include <vector>
#include <map>
#include <optional>
#include "mididevice.h"

namespace Layout {

	const std::map<unsigned char, note_t> layout
	{
		{'1', 59},
		{'Q', 60},
		{'2', 61},
		{'W', 62},
		{'3', 63},
		{'E', 64},
		{'4', std::nullopt},
		{'R', 65},
		{'5', 66},
		{'T', 67},
		{'6', 68},
		{'Y', 69},
		{'7', 70},
		{'U', 71},
		{'8', std::nullopt},
		{'I', 72},
		{'9', 73},
		{'O', 74},
		{'0', 75},
		{'P', 76},
	};
	// const std::vector<unsigned char> layout{ '1','Q','2','W','3','E','4','R','5','T','6','Y','7','U','8','I','9','O','0','P','-','[','=',']' };

}


#pragma once

#include <vector>
#include <map>
#include <optional>
#include "mididevice.h"
#include "playable.h"

namespace Layout {

	const std::map<unsigned char, std::unique_ptr<Playable>> layout
	{
		{'1', std::make_unique<SingleNote>(59)},
		{'Q', std::make_unique<SingleNote>(60)},
		{'2', std::make_unique<SingleNote>(61)},
		{'W', std::make_unique<SingleNote>(62)},
		{'3', std::make_unique<SingleNote>(63)},
		{'E', std::make_unique<SingleNote>(64)},
		{'4', std::make_unique<SingleNote>(std::nullopt)},
		{'R', std::make_unique<SingleNote>(65)},
		{'5', std::make_unique<SingleNote>(66)},
		{'T', std::make_unique<SingleNote>(67)},
		{'6', std::make_unique<SingleNote>(68)},
		{'Y', std::make_unique<SingleNote>(69)},
		{'7', std::make_unique<SingleNote>(70)},
		{'U', std::make_unique<SingleNote>(71)},
		{'8', std::make_unique<SingleNote>(std::nullopt)},
		{'I', std::make_unique<SingleNote>(72)},
		{'9', std::make_unique<SingleNote>(73)},
		{'O', std::make_unique<SingleNote>(74)},
		{'0', std::make_unique<SingleNote>(75)},
		{'P', std::make_unique<SingleNote>(76)},
	};
	// const std::vector<unsigned char> layout{ '1','Q','2','W','3','E','4','R','5','T','6','Y','7','U','8','I','9','O','0','P','-','[','=',']' };

};


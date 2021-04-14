#pragma once

#include <vector>
#include <map>
#include <optional>
#include "mididevice.h"
#include "playable.h"

namespace Layout {

	const std::map<unsigned char, std::shared_ptr<Playable>> layout
	{
		{'1', std::make_shared<SingleNote>(59)},
		{'Q', std::make_shared<SingleNote>(60)},
		{'2', std::make_shared<SingleNote>(61)},
		{'W', std::make_shared<SingleNote>(62)},
		{'3', std::make_shared<SingleNote>(63)},
		{'E', std::make_shared<SingleNote>(64)},
		{'4', std::make_shared<SingleNote>(std::nullopt)},
		{'R', std::make_shared<SingleNote>(65)},
		{'5', std::make_shared<SingleNote>(66)},
		{'T', std::make_shared<SingleNote>(67)},
		{'6', std::make_shared<SingleNote>(68)},
		{'Y', std::make_shared<SingleNote>(69)},
		{'7', std::make_shared<SingleNote>(70)},
		{'U', std::make_shared<SingleNote>(71)},
		{'8', std::make_shared<SingleNote>(std::nullopt)},
		{'I', std::make_shared<SingleNote>(72)},
		{'9', std::make_shared<SingleNote>(73)},
		{'O', std::make_shared<SingleNote>(74)},
		{'0', std::make_shared<SingleNote>(75)},
		{'P', std::make_shared<SingleNote>(76)},
	};
	// const std::vector<unsigned char> layout{ '1','Q','2','W','3','E','4','R','5','T','6','Y','7','U','8','I','9','O','0','P','-','[','=',']' };

};


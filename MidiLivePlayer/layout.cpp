#include "layout.h"

// Create a basic chromatic piano layout, given a keys vector and a base note to start with.
LayoutDict MakeChromaticLayout(std::vector<unsigned char> keys, int base)
{
	LayoutDict layout;
	int note = base;
	bool skipped = false;
	for (auto key : keys)
	{
		// Skip a key when there's a semitone between 'white' leys
		// Extra check for first note (note != base)
		if (!skipped && (note % 12 == 5 || (note % 12 == 0 && note != base)))
		{
			skipped = true;
			continue;
		} 
		else 
		{
			skipped = false;
			layout[key] = SingleNotePtr(note++);
		}
	}

	return layout;
}

#pragma once

#include <cstdint>
#include <vector>

class Keyboard {
private:
	std::vector<uint8_t> notes;
	std::vector<char> keys { '1','q','2','w','3','e','4','r','5','t','6','y','7','u','8','i','9','o','0','p','-','[','=',']' };
	uint8_t base;

	void RebaseKeyboard(uint8_t base);

public:
	Keyboard(uint8_t base = 60);
	uint8_t GetNote(char key);
	uint8_t operator[](char key);
};
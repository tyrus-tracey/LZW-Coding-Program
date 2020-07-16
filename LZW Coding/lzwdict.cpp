#include "lzwdict.h"
#include <iostream>

lzwdict::lzwdict()
	: codes(new std::string[1000]), position(5)
{
	codes[0] = "A";
	codes[1] = "B";
	codes[2] = "C";
	codes[3] = "D";
	codes[4] = "E";

}

lzwdict::~lzwdict()
{
	delete[] codes;
}

void lzwdict::insert(std::string symbol)
{
	if (position > 999) {
		return;
	}
	codes[position] = symbol;
	position++;
}

int lzwdict::getCode(std::string symbol)
{
	int code = -1;
	for (int i = 0; i < position; i++) {
		if (codes[i] == symbol) {
			code = i;
		}
	}
	return code;
}

bool lzwdict::exists(std::string symbol)
{
	for (int i = 0; i < position; i++) {
		if (codes[i] == symbol) {
			return true;
		}
	}
	return false;
}

void lzwdict::print()
{
	std::cout << "Dictionary:\n";
	for (int i = 0; i < position; i++) {
		std::cout << codes[i] << std::endl;
	}
}

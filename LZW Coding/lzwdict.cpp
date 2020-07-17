#include "lzwdict.h"
#include <iostream>
#include <iomanip>

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

bool lzwdict::hasCode(std::string symbol)
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
	std::cout << " string" << std::setw(12) << "code" << std::endl;
	std::cout << "----------------------" << std::endl;
	for (int i = 0; i < position; i++) {
		std::cout << "   " << codes[i] << std::setw(15 - codes[i].length()) << i << std::endl;
	}
}

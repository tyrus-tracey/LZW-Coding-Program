#include "lzwdict.h"
#include <iostream>
#include <iomanip>

//Creates an array-based lookup method of a fixed size (expands if limit reached)
lzwdict::lzwdict()
	: capacity(20), codes(new std::string[20]), position(5)
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

//insert string into dictionary, using index as the codeword
void lzwdict::insert(std::string symbol)
{
	if (position >= capacity) {
		expand();
	}
	codes[position] = symbol;
	position++;
}

//linear search of array, returns matching index (== codeword)
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

//linear search of array, returns true if match found
bool lzwdict::hasSymbol(std::string symbol)
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

// Allocates larger array and performs deepcopy if limit reached
void lzwdict::expand()
{
	std::string* newCodes = new std::string[position * 2];
	for (int i = 0; i < position; i++) {
		newCodes[i] = codes[i];
	}
	delete[] codes;
	codes = newCodes;
	capacity *= 2;
}

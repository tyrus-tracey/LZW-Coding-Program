#pragma once
#include <map>
#include <string>

class lzwdict
{
public:
	lzwdict();
	~lzwdict();
	void insert(std::string symbol);
	int getCode(std::string symbol);
	bool exists(std::string symbol);
	void print();

private:
	std::string* codes;
	int position;
};


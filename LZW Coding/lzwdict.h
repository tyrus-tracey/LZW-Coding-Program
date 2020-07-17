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
	bool hasCode(std::string symbol);
	void print();

private:
	void expand();
	std::string* codes;	//array-based dictionary
	int position;		//next available space in dictionary
	int capacity;		//default limit of 25
};


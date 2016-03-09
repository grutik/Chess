#pragma once

#include "Field.h";

class Board
{
public:
	static const int numberOfFields = 8;
	Field fields[numberOfFields][numberOfFields];
	Board();
	~Board();
};


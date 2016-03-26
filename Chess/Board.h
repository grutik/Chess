#pragma once

#include "Field.h";

class Board
{
public:
	static const int numberOfFields = 8;
	Field* selectedField;
	Field fields[numberOfFields][numberOfFields];
	
	Board();
	~Board();

	void CreateFields();
	void SetFigures();
	void MoveFigure(Field* destinationField);
};


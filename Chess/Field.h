#pragma once

#include "Figure.h";

class Field
{
public:

	int x;
	int y;
	int color;
	bool selected;
	Figure *currentFigure;

	Field();
	Field(int x, int y, int color);
	void Select();
	void Unselect();
	~Field();
};


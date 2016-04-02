#pragma once

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Field
{
public:

	int x;
	int y;
	int color;
	bool selected;
	Figure *fig;

	Field();
	Field(int x, int y, int color);
	void Select();
	void Unselect();
	~Field();
};


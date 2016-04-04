#pragma once

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

///
///  \brief Klasa reprezentująca pojedyncze pole szachownicy
///
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


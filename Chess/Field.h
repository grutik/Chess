#pragma once

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

///
///  \brief Klasa reprezentuj¹ca pojedyncze pole szachownicy
///
class Field
{
public:

	Field();
	Field(int x, int y, int color);
	~Field();

	int GetX();
	int GetY();
	int GetColor();
	bool HasFigure();
	Figure* GetFigure();
	void SetFigure(Figure* figure);
	void RemoveFigure();
	int IsSelected();

	void Select();
	void Unselect();

private:
	int _x;
	int _y;
	int _color;
	bool _selected;
	Figure* _fig;
};


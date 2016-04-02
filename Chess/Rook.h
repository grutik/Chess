#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook(bool isWhite);
	~Rook();
private:
	void InitBasicMoves();
};


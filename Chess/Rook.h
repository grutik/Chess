#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook(bool isWhite, int spriteXOffset);
	~Rook();
private:
	void InitBasicMoves();
};


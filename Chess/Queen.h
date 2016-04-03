#pragma once
#include "Figure.h"
class Queen :
	public Figure
{
public:
	Queen(bool isWhite, int spriteXOffset);
	~Queen();
private:
	void InitBasicMoves();
};


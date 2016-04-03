#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King(bool isWhite, int spriteXOffset);
	~King();
private:
	void InitBasicMoves();
};


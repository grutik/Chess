#pragma once
#include "Figure.h"
class Knight :
	public Figure
{
public:
	Knight(bool isWhite);
	~Knight();
private:
	void InitBasicMoves();
};


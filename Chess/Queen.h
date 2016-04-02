#pragma once
#include "Figure.h"
class Queen :
	public Figure
{
public:
	Queen(bool isWhite);
	~Queen();
private:
	void InitBasicMoves();
};


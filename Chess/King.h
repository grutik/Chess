#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King(bool isWhite);
	~King();
private:
	void InitBasicMoves();
};


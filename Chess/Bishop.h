#pragma once
#include "Figure.h"
class Bishop :
	public Figure
{
public:
	Bishop(bool isWhite, int spriteXOffset);
	~Bishop();
private:
	void InitBasicMoves();
};


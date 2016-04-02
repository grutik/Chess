#pragma once
#include "Figure.h"
class Bishop :
	public Figure
{
public:
	Bishop(bool isWhite);
	~Bishop();
private:
	void InitBasicMoves();
};


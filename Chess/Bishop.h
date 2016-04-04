#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj¹ca figurê goñca
///
class Bishop :
	public Figure
{
public:
	Bishop(bool isWhite, int spriteXOffset);
	~Bishop();
private:
	void InitBasicMoves();
};


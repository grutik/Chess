#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj¹ca figurê goñca
///
class Bishop :
	public Figure
{
public:
	Bishop(bool isWhite);
	~Bishop();
private:
	void InitBasicMoves();
};


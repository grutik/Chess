#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj�ca figur� go�ca
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


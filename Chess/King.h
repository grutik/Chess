#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj�ca figur� kr�la
///
class King : public Figure
{
public:
	King(bool isWhite);
	~King();
private:
	void InitBasicMoves();
};


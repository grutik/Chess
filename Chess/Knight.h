#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj�ca figur� skoczka
///
class Knight : public Figure
{
public:
	Knight(bool isWhite);
	~Knight();
private:
	void InitBasicMoves();
};


#pragma once
#include "Figure.h"
///
///  \brief Klasa reprezentuj�ca figur� wie�y
///

class Rook : public Figure
{
public:
	Rook(bool isWhite, int spriteXOffset);
	~Rook();
private:
	void InitBasicMoves();
};


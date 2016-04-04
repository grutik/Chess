#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj�ca figur� pionka
///
class Pawn : public Figure
{
public:
	Pawn(bool isWhite, int spriteXOffset);
	~Pawn();
private:
	void InitBasicMoves();
	void InitAttackMoves();
};


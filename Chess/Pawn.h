#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj�ca figur� pionka
///
class Pawn : public Figure
{
public:
	Pawn(bool isWhite);
	~Pawn();
private:
	void InitBasicMoves();
	void InitAttackMoves();
};


#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj¹ca figurê pionka
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


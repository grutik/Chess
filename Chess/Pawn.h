#pragma once
#include "Figure.h"
class Pawn :
	public Figure
{
public:
	Pawn(bool isWhite, int spriteXOffset);
	~Pawn();
private:
	void InitBasicMoves();
	void InitAttackMoves();
};


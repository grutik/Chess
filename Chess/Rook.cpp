#include "Rook.h"



Rook::Rook(bool isWhite, int spriteXOffset) : Figure(isWhite, spriteXOffset)
{
	_hasRecursiveMovement = true;
	_hasSpecialAttackAbilities = false;
	InitBasicMoves();
}


Rook::~Rook()
{
}

void Rook::InitBasicMoves()
{
	_basicMovesCount = 4;
	_basicMoves = new movement[_basicMovesCount];

	_basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y + 1 }; };
	_basicMoves[1] = [](int x, int y)->int* {return new int[2]{ x, y - 1 }; };
	_basicMoves[2] = [](int x, int y)->int* {return new int[2]{ x + 1, y }; };
	_basicMoves[3] = [](int x, int y)->int* {return new int[2]{ x - 1, y }; };
}
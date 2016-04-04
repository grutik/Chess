#include "Bishop.h"



Bishop::Bishop(bool isWhite, int spriteXOffset) : Figure(isWhite, spriteXOffset)
{
	_hasRecursiveMovement = true;
	_hasSpecialAttackAbilities = false;
	InitBasicMoves();
}

Bishop::~Bishop()
{
}

void Bishop::InitBasicMoves()
{
	_basicMovesCount = 4;
	_basicMoves = new movement[_basicMovesCount];

	_basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x + 1, y + 1 }; };
	_basicMoves[1] = [](int x, int y)->int* {return new int[2]{ x + 1, y - 1 }; };

	_basicMoves[2] = [](int x, int y)->int* {return new int[2]{ x - 1, y + 1}; };
	_basicMoves[3] = [](int x, int y)->int* {return new int[2]{ x - 1, y - 1}; };
}

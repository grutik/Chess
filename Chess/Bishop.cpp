#include "Bishop.h"



Bishop::Bishop(bool isWhite, int spriteXOffset) : Figure(isWhite, spriteXOffset)
{
	recursiveMovement = true;
	hasSpecialAttackAbilities = false;
	InitBasicMoves();
}

Bishop::~Bishop()
{
}

void Bishop::InitBasicMoves()
{
	basicMovesCount = 4;
	basicMoves = new movement[basicMovesCount];

	basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x + 1, y + 1 }; };
	basicMoves[1] = [](int x, int y)->int* {return new int[2]{ x + 1, y - 1 }; };

	basicMoves[2] = [](int x, int y)->int* {return new int[2]{ x - 1, y + 1}; };
	basicMoves[3] = [](int x, int y)->int* {return new int[2]{ x - 1, y - 1}; };
}

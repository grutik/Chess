#include "King.h"



King::King(bool isWhite, int spriteXOffset) : Figure(isWhite, spriteXOffset)
{
	_hasRecursiveMovement = false;
	_hasSpecialAttackAbilities = false;
	InitBasicMoves();
}

King::~King()
{
}

void King::InitBasicMoves()
{
	_basicMovesCount = 8;
	_basicMoves = new movement[_basicMovesCount];

	_basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y + 1 }; };
	_basicMoves[1] = [](int x, int y)->int* {return new int[2]{ x, y - 1 }; };

	_basicMoves[2] = [](int x, int y)->int* {return new int[2]{ x + 1, y }; };
	_basicMoves[3] = [](int x, int y)->int* {return new int[2]{ x - 1, y }; };

	_basicMoves[4] = [](int x, int y)->int* {return new int[2]{ x + 1, y + 1 }; };
	_basicMoves[5] = [](int x, int y)->int* {return new int[2]{ x + 1, y - 1 }; };

	_basicMoves[6] = [](int x, int y)->int* {return new int[2]{ x - 1, y + 1 }; };
	_basicMoves[7] = [](int x, int y)->int* {return new int[2]{ x - 1, y - 1 }; };
}

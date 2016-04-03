#include "Queen.h"


Queen::Queen(bool isWhite, int spriteXOffset) : Figure(isWhite, spriteXOffset)
{
	recursiveMovement = true;
	hasSpecialAttackAbilities = false;
	InitBasicMoves();
}

Queen::~Queen()
{
}

void Queen::InitBasicMoves()
{
	basicMovesCount = 8;
	basicMoves = new movement[basicMovesCount];

	basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y + 1 }; };
	basicMoves[1] = [](int x, int y)->int* {return new int[2]{ x, y - 1 }; };

	basicMoves[2] = [](int x, int y)->int* {return new int[2]{ x + 1, y }; };
	basicMoves[3] = [](int x, int y)->int* {return new int[2]{ x - 1, y }; };

	basicMoves[4] = [](int x, int y)->int* {return new int[2]{ x + 1, y + 1 }; };
	basicMoves[5] = [](int x, int y)->int* {return new int[2]{ x + 1, y - 1 }; };

	basicMoves[6] = [](int x, int y)->int* {return new int[2]{ x - 1, y + 1 }; };
	basicMoves[7] = [](int x, int y)->int* {return new int[2]{ x - 1, y - 1 }; };
}

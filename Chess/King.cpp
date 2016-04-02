#include "King.h"



King::King(bool isWhite) : Figure(isWhite)
{
	spriteOffset = 0;
	recursiveMovement = false;
	hasSpecialAttackAbilities = false;
	InitBasicMoves();
}

King::~King()
{
}

void King::InitBasicMoves()
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

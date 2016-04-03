#include "Knight.h"



Knight::Knight(bool isWhite, int spriteXOffset) : Figure(isWhite, spriteXOffset)
{
	recursiveMovement = false;
	hasSpecialAttackAbilities = false;
	InitBasicMoves();
}


Knight::~Knight()
{
}

void Knight::InitBasicMoves()
{
	basicMovesCount = 8;
	basicMoves = new movement[basicMovesCount];

	basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x + 2, y + 1 }; };
	basicMoves[1] = [](int x, int y)->int* {return new int[2]{ x + 2, y - 1 }; };

	basicMoves[2] = [](int x, int y)->int* {return new int[2]{ x - 2, y + 1 }; };
	basicMoves[3] = [](int x, int y)->int* {return new int[2]{ x - 2, y - 1 }; };

	basicMoves[4] = [](int x, int y)->int* {return new int[2]{ x + 1, y + 2 }; };
	basicMoves[5] = [](int x, int y)->int* {return new int[2]{ x - 1, y + 2 }; };

	basicMoves[6] = [](int x, int y)->int* {return new int[2]{ x + 1, y - 2 }; };
	basicMoves[7] = [](int x, int y)->int* {return new int[2]{ x - 1, y - 2 }; };
}

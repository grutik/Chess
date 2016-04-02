#include "Rook.h"



Rook::Rook(bool isWhite) : Figure(isWhite)
{
	type = Figure::Type::ROOK;
	recursiveMovement = true;
	hasSpecialAttackAbilities = false;
	InitBasicMoves();
}


Rook::~Rook()
{
}

void Rook::InitBasicMoves()
{
	basicMovesCount = 4;
	basicMoves = new movement[basicMovesCount];

	basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y + 1 }; };
	basicMoves[1] = [](int x, int y)->int* {return new int[2]{ x, y - 1 }; };
	basicMoves[2] = [](int x, int y)->int* {return new int[2]{ x + 1, y }; };
	basicMoves[3] = [](int x, int y)->int* {return new int[2]{ x - 1, y }; };
}
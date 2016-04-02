#include "Pawn.h"

Pawn::Pawn(bool isWhite) : Figure(isWhite)
{
	type = Figure::Type::PAWN;
	recursiveMovement = false;
	hasSpecialAttackAbilities = true;
	InitBasicMoves();
	InitAttackMoves();
}

Pawn::~Pawn()
{
}

void Pawn::InitBasicMoves()
{
	basicMovesCount = 1;
	basicMoves = new movement[basicMovesCount];
	if (white)
		basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y - 1 }; };
	else
		basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y + 1 }; };
}

void Pawn::InitAttackMoves()
{
	attackMovesCount = 2;
	attackMoves = new movement[attackMovesCount];

	if (white) {
		attackMoves[0] = [](int x, int y)->int* {return new int[2]{ x - 1, y - 1 }; };
		attackMoves[1] = [](int x, int y)->int* {return new int[2]{ x + 1, y - 1 }; };
	}
	else {
		attackMoves[0] = [](int x, int y)->int* {return new int[2]{ x - 1, y + 1 }; };
		attackMoves[1] = [](int x, int y)->int* {return new int[2]{ x + 1, y + 1 }; };
	}
};


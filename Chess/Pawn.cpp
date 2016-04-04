#include "Pawn.h"

Pawn::Pawn(bool isWhite, int spriteXOffset) : Figure(isWhite, spriteXOffset)
{
	_hasRecursiveMovement = false;
	_hasSpecialAttackAbilities = true;
	InitBasicMoves();
	InitAttackMoves();
}

Pawn::~Pawn()
{
}

void Pawn::InitBasicMoves()
{
	_basicMovesCount = 1;
	_basicMoves = new movement[_basicMovesCount];
	if (_isWhite)
		_basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y - 1 }; };
	else
		_basicMoves[0] = [](int x, int y)->int* {return new int[2]{ x, y + 1 }; };
}

void Pawn::InitAttackMoves()
{
	_attackMovesCount = 2;
	_attackMoves = new movement[_attackMovesCount];

	if (_isWhite) {
		_attackMoves[0] = [](int x, int y)->int* {return new int[2]{ x - 1, y - 1 }; };
		_attackMoves[1] = [](int x, int y)->int* {return new int[2]{ x + 1, y - 1 }; };
	}
	else {
		_attackMoves[0] = [](int x, int y)->int* {return new int[2]{ x - 1, y + 1 }; };
		_attackMoves[1] = [](int x, int y)->int* {return new int[2]{ x + 1, y + 1 }; };
	}
};


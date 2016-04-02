#pragma once


class Figure
{
public:
	enum class Type : int {
		PAWN = 6,
		ROOK = 5,
		KNIGHT = 4,
		BISHOP = 3,
		QUEEN = 2,
		KING = 1
	};

	Type type;
	bool white;
	bool recursiveMovement;
	bool hasSpecialAttackAbilities;

	// Tablica wskaŸników na funkcje umo¿liwiaj¹ce poruszanie siê
	typedef int*(*movement)(int x, int y);
	
	movement* basicMoves;
	int basicMovesCount;

	movement* attackMoves;
	int attackMovesCount;

	Figure();
	Figure(bool white);

	~Figure();

private:
	virtual void InitBasicMoves() = 0;
};


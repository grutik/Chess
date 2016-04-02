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

	// Tablica wskaŸników na funkcje umo¿liwiaj¹ce poruszanie siê
	typedef int*(*WSKF)(int x, int y);
	WSKF* availableMovements;


	Figure();
	Figure(Type figureType, bool white);

	static int* pawnMove(int x, int y);

	~Figure();
};


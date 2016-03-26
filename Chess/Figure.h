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

	Figure();
	Figure(Type figureType, bool white);
	~Figure();
};


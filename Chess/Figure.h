#pragma once


class Figure
{
public:
	int spriteOffset;
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


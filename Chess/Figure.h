#pragma once


class Figure
{
public:
	int spriteOffset;
	bool white;
	bool recursiveMovement;
	bool hasSpecialAttackAbilities;

	// Tablica wska�nik�w na funkcje umo�liwiaj�ce poruszanie si�
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


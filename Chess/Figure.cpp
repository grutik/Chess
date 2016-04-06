#include "Figure.h"

Figure::Figure(bool isWhite)
{
	_isWhite = isWhite;
	_hasSpecialAttackAbilities = false;
	_hasRecursiveMovement = true;
}

Figure::~Figure()
{
}

bool Figure::IsWhite() {
	return _isWhite;
}

bool Figure::HasSameColor(Figure * figure)
{
	return this->IsWhite() == figure->IsWhite();
}

bool Figure::HasDifferentColor(Figure * figure)
{
	return !this->HasSameColor(figure);
}

bool Figure::HasRecursiveMovement()
{
	return _hasRecursiveMovement;
}

bool Figure::HasSpecialAttackAbilities()
{
	return _hasSpecialAttackAbilities;
}

Figure::movement* Figure::GetBasicMoves()
{
	return _basicMoves;
}

int Figure::GetBasicMovesCount()
{
	return _basicMovesCount;
}

Figure::movement* Figure::GetAttackMoves()
{
	return _attackMoves;
}

int Figure::GetAttackMovesCount()
{
	return _attackMovesCount;
}


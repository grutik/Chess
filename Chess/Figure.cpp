#include "Figure.h"

Figure::Figure()
{
}

Figure::Figure(bool isWhite)
{
	white = isWhite;
	hasSpecialAttackAbilities = false;
	recursiveMovement = true;
}


Figure::~Figure()
{
}

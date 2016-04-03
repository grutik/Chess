#include "Figure.h"

Figure::Figure()
{
}

Figure::Figure(bool isWhite, int spriteXOffset)
{
	spriteOffset = spriteXOffset;
	white = isWhite;
	hasSpecialAttackAbilities = false;
	recursiveMovement = true;
}


Figure::~Figure()
{
}

#include "Figure.h"



int* Figure::pawnMove(int x, int y)
{
	int destinationCords[2] = { x ,y + 1 };

	return destinationCords;
}

Figure::Figure()
{
}

Figure::Figure(Type figureType, bool isWhite)
{
	type = figureType;
	white = isWhite;

	availableMovements = new WSKF[1];
	availableMovements[0] = pawnMove;
}


Figure::~Figure()
{
}

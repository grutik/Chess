#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj�ca figur� kr�lowej
///
class Queen : public Figure
{
public:
	Queen(bool isWhite);
	~Queen();
private:
	void InitBasicMoves();
};


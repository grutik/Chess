#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj¹ca figurê skoczka
///
class Knight : public Figure
{
public:
	Knight(bool isWhite);
	~Knight();
private:
	void InitBasicMoves();
};


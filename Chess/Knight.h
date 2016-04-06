#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentująca figurę skoczka
///
class Knight : public Figure
{
public:
	Knight(bool isWhite);
	~Knight();
private:
	void InitBasicMoves();
};


#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj¹ca figurê królowej
///
class Queen : public Figure
{
public:
	Queen(bool isWhite);
	~Queen();
private:
	void InitBasicMoves();
};


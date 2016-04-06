#pragma once
#include "Figure.h"
///
///  \brief Klasa reprezentuj¹ca figurê wie¿y
///

class Rook : public Figure
{
public:
	Rook(bool isWhite);
	~Rook();
private:
	void InitBasicMoves();
};

